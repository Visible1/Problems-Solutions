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
ld eps = 1e-13;
ifstream in;
ofstream out;

void deal(){	
	ll n, m;
	cin>>n>>m;
	
	vector<vector<ll> > dp(n+1, vector<ll>(m+1, 0));
	
	vector<vector<ll > > arr(n+1, vector<ll>(m+1 ));
	
	for(ll i = 1; i<=n; i++){
		for(ll j = 1; j<=m; j++){
			cin>>arr[i][j];
		}
	}
	
	ll ans= 0;
	ll l1, l2;
	
	for( ll i = 1; i<=n; i++){
		for(ll j = 1; j<=m; j++){
			if(arr[i][j] == 1){
				ll mn = min(dp[i-1][j], dp[i][j-1]);
				if(arr[i-mn][j-mn] == 1){
					dp[i][j] = mn+1;
				}
				else{
					dp[i][j] = mn;
				}
			}
			if(dp[i][j] >= ans){
				ans = dp[i][j];
				l1 = i-dp[i][j];
				l2 = j-dp[i][j];
			}
		}
	}
	
	
	
	cout<<ans<<'\n'<<l1+1<<" "<<l2+1<<'\n';
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
