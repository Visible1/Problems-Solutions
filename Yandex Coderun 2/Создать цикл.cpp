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
ll modulo = pow(10,9) + 7;
ld eps = 1e-13;
ifstream in;
ofstream out;

#define MAX 100'010

ll high[MAX];
ll dep[MAX];
ll sz[MAX];
ll dp[MAX];
vector<ll> g[MAX];
vector<ll> gf[MAX];

ll ans;

void dfs1(ll hd){
	for(auto hr : g[hd]){
		if(dep[hr] == -1){
			gf[hd].pb(hr);
			dep[hr] = dep[hd] + 1;
			dfs1(hr);
		}
	}
}

void dfs2(ll hd){
	high[hd] = dep[hd];
	sz[hd] = 1;
	dp[hd] = 1;
	
	for(auto& hr : gf[hd]){
		dfs2(hr);
		sz[hd] += sz[hr];
		dp[hd] += dp[hr];
		high[hd] = min(high[hd], high[hr]);
	}
	
	for(auto& hr : g[hd]){
		if(dep[hr] == dep[hd] - 1){
			// it is parent
			continue;
		}
		high[hd] = min(high[hd], dep[hr]);
	}
	
	
	if(high[hd] != dep[hd] || dep[hd] == 0){
		ll vl = dp[hd];
		ans += vl * (vl-1) / 2;
		ans -= (vl - 1);
		dp[hd] = 0;
	}
}

void deal(){	
	ll n, m;
	cin>>n>>m;
	
	fori(n){
		dep[i] = -1;
	}
	
	fori(m){
		ll ai, bi;
		cin>>ai>>bi;
		--ai, --bi;
		g[ai].pb(bi);
		g[bi].pb(ai);
	}
	
	fori(n){
		if(dep[i] == -1){
			dep[i] = 0;
			dfs1(i);
			dfs2(i);
		}
	}
	
	
	cout<<ans;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
