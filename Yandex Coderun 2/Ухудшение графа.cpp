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


vector<ll> getDt(vector<vector<ll> >& adj){
	ll n = adj.size();
	vector<ll> dt(n, inf);
	dt[0] = 0;
	vector<bool> took(n, 0);
	while(1){
		ll mn = inf;
		ll lz = -1;
		forj(n){
			if(!took[j] && dt[j] < mn){
				mn = dt[j];
				lz = j;
			}
		}
		if(lz == -1){
			break;
		}
		took[lz] = 1;
		forj(n){
			if(adj[lz][j]!=-1){
				dt[j] = min(dt[j] , dt[lz] + adj[lz][j]);
			}
		}
	}
	
	return dt;
}


void deal(){	
	ll n;
	cin>>n;
	
	vector<vector<ll> > adj(n, vector<ll>(n));
	
	
	fori(n){
		forj(n){
			cin>>adj[i][j];
		}
	}
	
	auto ini = getDt(adj);
	
	ll mx = 0;
	
	fori(n){
		auto cur = adj;
		cur[0][i] = -1;
		auto curd = getDt(cur);
		
		ll s = 0;
		forj(n){
			if(curd[j] != ini[j]){
				++s;
			}
		}
		
		mx = max(mx, s);
	}
	
	cout<<mx;
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
