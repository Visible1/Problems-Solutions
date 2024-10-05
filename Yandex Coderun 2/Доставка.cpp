#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define forx(v) for(int x=0; x<v; x++)
#define fory(v) for(int y=0; y<v; y++)
#define ll long long
#define lll __int128
#define ld long double
#define pb(a) push_back(a)
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = 2 * pow(10, 18);
ll modulo = 998244353;
ifstream in;
ofstream out;

struct line{
    ll ki, bi;
    ll que(ll x){
        return ki * x + bi;
    }
};

struct hull{
    vector<pair<ll, line> > arr; // (optimal start, line)
    ll que(ll x){
        ll lo = 0, hi = (ll)arr.size()-1;
        while(lo < hi){
            ll mid = (lo + hi)/2 + 1;
            if(arr[mid].ff <= x){
                lo = mid;
            }
            else{
                hi = mid-1;
            }
        }
        return arr[lo].ss.que(x);
    }
};

bool J(line& a, line& b){
    if(a.ki != b.ki){
        return a.ki > b.ki;
    }
    return a.bi > b.bi;
}

hull cons(vector<pair<ll, ll> >& arr, ll l, ll r){
    // .ff = coord, .ss = price
    // (xj - xi) ^ 2 + price = xj ^ 2 - 2 * xj * xi + xi ^ 2 + price
    // so we have line (-2*xi) = ki, and then bi = xi ^ 2 + price
    vector<line> all;
    
    for(ll i = l; i<=r; i++){
        auto& el = arr[i];
        ll xi = el.ff, price = el.ss;
        ll ki = -2*xi;
        ll bi = xi * xi + price;
        all.pb(line({ki, bi}));
    }

    sort(all.begin(), all.end(), J);
    // biggest ki  to smallest ki

    hull ans;
    auto& srt = ans.arr;

    for(auto& el : all){
        ll k2 = el.ki, b2 = el.bi;
        while(!srt.empty()){
            ll k1 = srt.back().ss.ki, b1 = srt.back().ss.bi;
            if(b2 <= b1){
                srt.erase(srt.end()-1);
            }
            else{
                // we know b2 > b1, so it has to be k2 != k1, and k2 < k1
                ll x = (b2 - b1) / (k1 - k2);
                // they intersect at x, so:
                // after x new line is better
                if(x * (k1-k2) != (b2 - b1)){
                    x++;
                }
                if(x <= srt.back().ff){
                    srt.erase(srt.end()-1);
                }
                else{
                    srt.pb(mp(x, el));
                    break;
                }
            }
        }
        if(srt.empty()){
            srt.pb(mp(0, el));
        }
    }

    return ans;
}

struct query{
    ll xj, li, ri, qi;
};

void divConq(ll l, ll r, vector<pair<ll,ll> >& arr, vector<query>& que, vector<ll>& ans){
    if(que.empty()){
        return;
    }
    vector<query> queL, queR;
    // construct hull

    hull cur = cons(arr, l, r);

    ll mid = (l+r)/2;

    for(auto& el : que){
        if(el.li <= l && el.ri >= r ){
            // if the current (l, r) is enough for query
            // then find ans
            ll qi = el.qi;
            ll xj = el.xj;
            ans[qi] = min(ans[qi], cur.que(xj) + xj * xj);
        }
        else if(el.ri <= mid){
            queL.pb(el);
        }
        else if(el.li > mid){
            queR.pb(el);
        }
        else{
            queL.pb(el);
            queR.pb(el); 
            // should happen at most logn times per query object
        }
    }

    vector<query>().swap(que);
    vector<pair<ll, line> >().swap(cur.arr);

    divConq(l, mid, arr,  queL, ans);
    divConq(mid+1, r, arr, queR, ans);
}
 
void deal(){
    ll n , m;
    cin>>n>>m;

    vector<pair<ll, ll> > arr(n);

    fori(n){
        cin>>arr[i].ff>>arr[i].ss;
    }

    vector<query> que;

    fori(m){
        ll ci, ki;
        cin>>ci>>ki;

        set<ll> cur;
        
        forj(ki){
            ll pt;
            cin>>pt;
            --pt;
            cur.insert(pt);
        }
        
        ll pv = 0;

        for(auto& pt : cur){
            if(pv != pt){
                que.pb(query({ci, pv, pt-1, i}));
            }
            pv = pt+1;
        }

        if(pv != n){
            que.pb(query({ci, pv, n-1, i}));
        }
    }

    vector<ll> ans(m, inf);

    divConq(0, n-1, arr, que, ans);

    fori(m){
        cout<<ans[i]<<'\n';
    }

}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
