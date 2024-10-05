#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define lll __int128
#define ld long double
#define pb(a) push_back(a)
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = 998244353;
ifstream in;
ofstream out;

// find all primes up to sqrt(10^9)

vector<ll> primes;

#define MAX 100'100

bool isp[MAX];

void pre(){
    const ll lim = 1'000'000'010;

    fori(MAX){
        isp[i] = 1;
    }
    isp[0] =0, isp[1] = 0;
    for(ll i = 2; i<MAX; i++){
        if(isp[i]){
            for(ll j = 2*i; j<MAX; j+=i){
                isp[j] = 0;
            }
            if( i * i < lim){
                primes.pb(i);
            }
        }
    }
}

bool J(vector<ll>& a, vector<ll>& b){
    return a[2] < b[2];
}


vector<vector<ll> > getTimes(vector<ll>& arr, vector<vector<ll> >& que){
    ll q = que.size();
    ll n = arr.size();

    ll ps = primes.size();

    vector<vector<ll> > when(q); // when is it totally divisible by those numbers (e.g. return answer)


    // for small primes , save what count is needed to wait and watch

    vector<deque<vector<ll> > > watch(ps);

    vector<vector<ll > > big(q); // big primes needed for each number

    fori((ll)que.size()){
        ll sz =  que[i].size();
        when[i] = vector<ll>(sz, 0);
        big[i] = vector<ll> (sz, 1);
        
        forj((ll)que[i].size()){
            ll vl = que[i][j];

            fork((ll) primes.size()){
                ll pr = primes[k];

                if(vl % pr == 0){
                    ll cnt = 0;
                    while(vl % pr == 0){
                        vl /= pr;
                        cnt++;
                    }
                    // query i, number indexed j, and waiting for count
                    watch[k].pb(vector<ll>({i, j, cnt}));
                }
            }

            if(vl != 1){
                // big prime alert
                big[i][j] = vl;
            }
        }
    }

    // forgot to sort
    fori(ps){
        sort(watch[i].begin(), watch[i].end(), J);
    }

    vector<ll> tot(ps, 0); // counts for primes

    map<ll, ll> frs; // for big primes when did it first occur
    frs[1] = 0;

    for(ll i = 1; i<n; i++){
        ll vl = arr[i];
        forj(ps){
            ll pr = primes[j];

            if(vl % pr == 0){
                while(vl % pr == 0){
                    vl /= pr;
                    tot[j]++;
                }

                while(!watch[j].empty()
                    && tot[j] >= watch[j][0][2] ){
                    ll i1 = watch[j][0][0], i2 = watch[j][0][1];
                    when[i1][i2] = max(when[i1][i2], i);
                    watch[j].pop_front();
                }
            }
        }

        if(vl != 1){
            if(frs.find(vl) == frs.end()){
                frs[vl] = i;
            }
        }
    }

    fori(ps){
        for(auto& el : watch[i]){
            ll i1 = el[0], i2 = el[1];
            when[i1][i2] = inf;
        }
    }

    fori(q){
        forj((ll)que[i].size()){
            ll cr = big[i][j];
            
            auto it = frs.find(cr);
            if(it == frs.end()){
                when[i][j] = inf;
            }
            else{
                when[i][j] = max(when[i][j], (*it).ss);
            }
        }
    }

    return when;
}

void deal(){
    pre();

    ll n, m, q;
    cin>>n>>m>>q;

    ++n, ++m;

    vector<ll> a1(n), a2(m);
    vector<ll> p1(n), p2(m);

    vector<vector<ll> > que(q);

    fori(n){
        cin>>a1[i];
    }

    fori(m){
        cin>>a2[i];
    }

    fori(n){
        cin>>p1[i];
    }

    fori(m){
        cin>>p2[i];
    }

    fori(q){
        ll sz;
        cin>>sz;
        que[i].resize(sz);

        forj(sz){
            cin>>que[i][j];
        }
    }


    vector<ll> pf1(n), pf2(m);

    {
        pf1[0] = p1[0];
        for(ll i = 1; i<n; i++){
            pf1[i] = min(pf1[i-1], p1[i]);
        }
    }

    {   
        pf2[0] = p2[0];
        for(ll i = 1; i <m; i++){
            pf2[i] = min(pf2[i-1], p2[i]);
        }
    }

    vector<vector<ll> > times1 = getTimes(a1, que), times2 = getTimes(a2, que);

    fori(q){
        vector<pair<ll, ll> > lims;
        forj(que[i].size()){
            ll t1 = times1[i][j], t2 = times2[i][j];
            if(t1 != inf && t2 != inf){
                lims.pb(mp(t1, t2));
            }
        }

        sort(lims.begin(), lims.end());

        // save the limit for second array
        ll lim = m;

        ll answer = inf;

        for(auto& el : lims){
            ll i1 = el.ff, i2 = el.ss;
            answer = min(answer, pf1[i1-1] + pf2[lim-1]);
            lim = min(lim, i2);
        }

        answer = min(answer, pf1[n-1] + pf2[lim-1]);

        cout<<answer<<'\n';
    }

}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
