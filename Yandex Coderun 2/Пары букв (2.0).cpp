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

void deal(){
    const ll mxN = 20;
    vector<ll> dp(1<<mxN, 0); 
    // "i" is the mask of the nodes that ended up being odd,
    // value is the sum of total ways
    dp[0] = 1;

    ll n, k;
    cin>>n>>k;

    vector<pair<ll, ll> > edg;

    fori(n){
        string a;
        cin>>a;
        edg.pb(mp(a[0]-'A', a[1] - 'A'));
    }

    auto check = [](vector<pair<ll, ll> >& edg){
        const ll mxN = 20;
        vector<vector<ll> > g(mxN);

        vector<bool> need(mxN, 0);
        for(auto& ei : edg){
            ll ai = ei.ff, bi = ei.ss;
            g[ai].pb(bi);
            g[bi].pb(ai);
            need[ai] = 1, need[bi] = 1;
        }

        fori(mxN){
            if(!g[i].empty()){
                vector<bool> seen(mxN, 0);

                seen[i] = 1;
                vector<ll> bfs({i});

                forj((ll)bfs.size()){
                    ll hd = bfs[j];
                    for(auto& hr : g[hd]){
                        if(!seen[hr]){
                            seen[hr] = 1;
                            bfs.pb(hr);
                        }
                    }
                }

                forj(mxN){
                    if(need[j] && !seen[j]){
                        return false;
                    }
                }

                return true;
            }
        }
    };

    if(!check(edg)){
        cout<<0;
        return;
    }

    ll self = 1;
    for(auto& ei : edg){
        if(ei.ff == ei.ss){
            self *= k;
            self %= modulo;
            continue;
        }

        vector<ll> dpn(1<<mxN, 0);

        ll cr = ((1<<ei.ff) | (1<<ei.ss));

        fori(1<<mxN){
            dpn[i] += dp[i] * (k/2);
            dpn[i] += dp[i ^ cr] * ((k+1)/2);

            dpn[i] %= modulo;
        }

        dp = dpn;
    }

    ll ans = 0;

    fori(1<<mxN){
        ll cnt = __builtin_popcount(i);
        if(cnt == 0 || cnt == 2){
            ans += dp[i] * self;
            ans %= modulo;
        }
    }

    cout<<ans;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
