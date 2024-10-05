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

// pair = (totalSame, lis)

pair<ll, ll> lis(vector<ll> a1, vector<ll> a2){
	map<ll, ll> place;
	
	fori((ll)a2.size()){
		place[a2[i]] = i;
	}
	
	ll tot = 0;
	set<ll> ids;
	
	fori((ll)a1.size()){
		ll ed = a1[i];
		if(ed){
			auto it = place.find(ed);
			if(it != place.end()){
				++tot;
				ll id = (*it).ss;
				auto nx = ids.lower_bound(id);
				if(nx != ids.end()){
					ids.erase(nx);
				}
				ids.insert(id);
			}
		}
	}
	
	return mp(tot, ids.size());
}

void deal(){	
	ll n, m;
	cin>>n>>m;
	
	vector<vector<ll> > a1(n, vector<ll>(m, 0));
	vector<vector<ll> > a2(n, vector<ll>(m, 0));
	
	fori(n){
		forj(m){
			cin>>a1[i][j];
		}
	}
	
	fori(n){
		forj(m){
			cin>>a2[i][j];
		}
	}
	
	if(a1 == a2){
		cout<<0;
		return;
	}
	
	bool zero = 0;
	
	fori(n){
		forj(m){
			if(a1[i][j] == 0){
				zero = 1;
			}
		}
	}
	
	if(!zero){
		cout<<-1;
		return;
	}
	
	vector<bool> noz(n, 1); // meaning a row has no zeros
	// in both tables
	
	fori(n){
		forj(m){
			if(a1[i][j] == 0 || a2[i][j] == 0){
				noz[i] = 0;
			}
		}
	}
	
	vector<pair<ll, ll> > nums(n * m + 10, mp(-1, -1));
	
	fori(n){
		forj(m){
			ll v1 = a1[i][j];
			if(v1){
				nums[v1].ff = i;
			}
			ll v2 = a2[i][j];
			if(v2){
				nums[v2].ss = i;
			}
		}
	}
	
	
	// count number of components with all noz
	vector<vector<ll> > g(n);
	ll ans = 0;
	
	fori(n*m+10){
		ll a = nums[i].ff, b = nums[i].ss;
		if(a != b ){
			g[a].pb(b);
			g[b].pb(a);
			ans++;
		}
	}
	
	fori(n){
		auto cur = lis(a1[i], a2[i]);
		if(cur.ff != cur.ss){
			g[i].pb(i);
			ans += cur.ff-cur.ss;
		}
	}
	
	vector<bool> vis(n*m + 10, 0);
	
	fori(n){
		if(!vis[i] && !g[i].empty()){
			vector<ll> bfs({i});
			vis[i] =  1;
			forj((ll)bfs.size()){
				ll hd = bfs[j];
				for(auto& hr : g[hd]){
					if(!vis[hr]){
						vis[hr] = 1;
						bfs.pb(hr);
					}
				}
			}
			bool all = 1;
			for(auto& el : bfs){
				if(!noz[el]){
					all = 0;
				}
			}
			if(all){
				ans++;
			}
		}
	}
	
	// no need to count zeros
	
	cout<<ans;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
