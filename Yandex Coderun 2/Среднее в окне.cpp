#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
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
ll inf = pow(10, 18);
ll modulo = 998244353;
ld eps = 1e-9;
ifstream in;
ofstream out;
 
void deal(){
    ll n, k;
    cin>>n>>k;
    vector<ll> arr(n+1, 0);
    for(ll i = 1; i<=n; i++){
        cin>>arr[i];
    }

    vector<ll> pf(n+1, 0);
    for(ll i = 1; i<=n; i++){
        pf[i] = pf[i-1] + arr[i];
    }

    ld lo = 0, hi = 1e7;

    while(hi - lo > eps){
        ld mid = (lo + hi)/2;
        ld mn = inf;

        bool gg = 0;

        for(ll i = 1; i<=n; i++){
            if(i - k >= 0){
                mn = min(mn, pf[i-k] - (i-k) * mid);
            }
            ld vl = pf[i] - i * mid;
            if(vl >= mn){
                gg = 1;
                break;
            }
        }

        if(gg){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }

    cout<<setp(13)<<lo;

}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
