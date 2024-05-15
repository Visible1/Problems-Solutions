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
ll modulo = pow(10, 9) + 7;
ld eps = 1e-13;
ifstream in;
ofstream out;


#define MAX 100'100

vector<ll> g[MAX];
ll ini[MAX];
ll sumIni[MAX]; // sum of inital times
ll num[MAX];

bool J(vector<ll>& a, vector<ll>& b){
	return b[0] * a[1] < a[0] * b[1];
}

void dfs(ll hd){
	vector<vector<ll> > all;
	sumIni[hd] += ini[hd];
	num[hd] = 1;
	
	for(auto& hr : g[hd]){
		dfs(hr);
		sumIni[hd] += sumIni[hr];
		num[hd] += num[hr];
		all.pb(vector<ll>({num[hr], sumIni[hr], hr}));
	}
	
	sort(all.begin(), all.end(), J);
	
	fori((ll)all.size()){
		g[hd][i] = all[i][2];
	}
}

void dfs2(ll hd, ll& stamp, ll& ans){
	++stamp;
	for(auto& hr : g[hd]){
		dfs2(hr, stamp, ans);
	}
	stamp += ini[hd];
	ans += stamp;
}

void deal(){
	ll n;
	cin>>n;
	fori(n){
		cin>>ini[i];
		
		ll fi;
		cin>>fi;
		forj(fi){
			ll hr;
			cin>>hr;
			--hr;
			g[i].pb(hr);
		}
		
	}
	
	dfs(0);
	
	{
		ll stamp = 0;
		ll ans = 0;
		dfs2(0, stamp, ans);
		cout<<ans;
	}
	
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

