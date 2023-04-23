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
#define ll long long
#define lll __int128
#define ld long double
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = (ll)pow(10, 18);
ll modulo = pow(10, 9) + 7;
ld eps = 1e-13;
ifstream in;
ofstream out;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0 , -1};

void deal(){
      ll n, m , k;
      cin>>n>>m>>k;
      vector<vector<ll> > arr(n+2, vector<ll>(m+2, inf));
      fori(n){
            forj(m){
                  cin>>arr[i+1][j+1];
            }
      }
      ll lo = 1, hi = (ll)1e9 + 10;
      while(lo < hi){
            ll mid = (lo + hi)/2;
            vector<pair<ll, ll> > bfs;
            vector<vector<bool> > seen(n+2, vector<bool>(m+2, 0));
            
            bfs.pb(mp(0, 0));
            seen[0][0] = 1;
            fori((ll)bfs.size()){
                  ll xi = bfs[i].ff, yi = bfs[i].ss;
                  forj(4){
                        ll x2 = xi + dx[j], y2 = yi + dy[j];
                        if(x2 > -1 && y2 > -1 && x2 < n+2 && y2 < m+2 && arr[x2][y2] > mid
                              && !seen[x2][y2]){
                              bfs.pb(mp(x2, y2));
                              seen[x2][y2] = 1;
                        }
                  }
            }
            
            if((n+2) * (m+2) - (ll)bfs.size() < k){
                  lo = mid+1;
            }
            else{
                  hi = mid;
            }
      }
      
      cout<<lo;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
      
      return 0;
}
