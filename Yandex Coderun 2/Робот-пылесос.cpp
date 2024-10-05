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

#define MAX 2020

ll when[MAX][MAX];

inline vector<ll> getState(vector<vector<ll> >& cir, ll w, ll h, ll add){
	
	ll n = cir.size();
	
	vector<vector<bool> > ad(n, vector<bool>(n, 0));
	
	fori(n){
		for(ll j = i+1; j<n; j++){
			if(add >= when[i][j]){
				ad[i][j] = 1;
				ad[j][i] = 1;
			}		
		}
	}
	
	vector<vector<ll> > adj(4, vector<ll>(4, 0));
	fori(4){
		for(ll dif = -1; dif<=1; dif+=2){
			ll j = (i + dif + 4) % 4;
			adj[i][j] = 1;
		}
	}
	
	
	vector<bool> vis(n, 0);
	
	fori(n){
		if(!vis[i]){
			vis[i] = 1;
			vector<ll> bfs({i});
			
			forj((ll)bfs.size()){
				ll hd = bfs[j];
				fork(n){
					ll hr = k;
					if(ad[hd][hr] && !vis[hr]){
						vis[hr] = 1;
						bfs.pb(hr);
					}
				}
			}
			
			vector<ll> mns({inf, inf});
			vector<ll> mxs({-inf, -inf});
			
			for(auto& el : bfs){
				forj(2){
					mns[j] = min(mns[j], cir[el][j] - cir[el][2]);
					mxs[j] = max(mxs[j], cir[el][j] + cir[el][2]);
				}
			}
			
			// mns[0] - add < 0   => edge 0-1
			// mxs[0] + add > w   => edge 2-3
			// mns[1] - add < 0   => edge 0-3
			// mxs[1] + add > h   => edge 1-2
			
			vector<pair<ll, ll> > edgs;
			
			
			if(mns[0] - 2*add < 0 && mxs[0] + 2*add > w){
				edgs.pb(mp(0, 3));
				edgs.pb(mp(1, 2));
			}
			if(mns[1] - 2*add < 0 && mxs[1] + 2*add > h){
				edgs.pb(mp(0, 1));
				edgs.pb(mp(2, 3));
			}
			
			if((ll)edgs.size() > 1){
				for(auto& el : edgs){
					ll a= el.ff, b= el.ss;
				//	cout<<a<<" "<<b<<" bad "<<endl;
					adj[a][b] = 0;
					adj[b][a] = 0;
				}
			}
			
		}
	}
	
	vector<ll> state(4, 0);
	
	ll cmp = 0;
	
	fori(4){
		if(state[i] == 0){
			++cmp;
			state[i] = cmp;
			vector<ll> bfs({i});
			
			forj((ll)bfs.size()){
				ll hd = bfs[j];
				fork(4){
					ll hr = k;
					if(adj[hd][hr] && state[hr] == 0){
						state[hr] = cmp;
						bfs.pb(hr);
					}
				}
			}
		}
	}
	
	return state;
}


void display(vector<ll> all){
	for(auto e : all){
		cout<<e<<' ';
	}
	cout<<endl;
}


void deal(){	
	srand(time(NULL));
	
	ll n = 2000, m = 0;

	cin>>n>>m;
	
	ll w = 1e9, h = 1e9;
	
	cin>>w>>h;
	
	vector<vector<ll> > cir(n, vector<ll>(3));
	
	fori(n){
		ll x = rand() % (ll) (1e9) ;
		ll y = rand() % (ll) (1e9) ;
		ll r = rand() % (ll) (1e8) ;
		cir[i] = vector<ll>({x, y, r}); 
		forj(3){
			cin>>cir[i][j];
		}
	}
	
	
	fori(n){
		for(ll j = i+1; j<n; j++){
			// distance < r1 + r2 + 2*add
			// square both sides
			auto e1 = cir[i], e2 = cir[j];
			
			ll d = (e1[0] - e2[0]) * (e1[0] - e2[0]) + (e1[1] - e2[1]) * (e1[1] - e2[1]);
			
			// ll s = (e1[2] + e2[2] + 2*x) * (e1[2] + e2[2] + 2*x);
			
			ll x = ( sqrt(d) - e1[2] - e2[2] ) / 2;
			
			while(1){
				ll s = (e1[2] + e2[2] + 2*x) * (e1[2] + e2[2] + 2*x);
				if(s > d){
					break;
				}
				x++;
			}
			
			when[i][j] = x;		
		}
	}
	
	vector<pair<ll, vector<ll> > > save;
	save.pb(mp(0, vector<ll>(4, 1)));
	
	
	while(1){
		ll lo= save.back().ff, hi = max(w, h) + 10;
		while(lo < hi){
			ll mid = (lo + hi)/2;
			auto cur = getState(cir, w, h, mid);
			if(cur != save.back().ss){
				hi = mid;
			}
			else{
				lo = mid+1;
			}
		}
		if(lo == max(w, h) + 10){
			break;
		}
		save.pb(mp(lo, getState(cir, w, h, lo)));
		
	}
	
	fori(m){
		ll ri, si;
		cin>>ri>>si;
		ll lz = -1;
		fori((ll)save.size()){
			if(ri >= save[i].ff){
				lz = i;
			}
		}
		
		--si;
		
		string all = "";
		
		auto need = save[lz].ss;
		
		fori(4){
			if(need[i] == need[si]){
				all += (char)(i + 1 + '0');
			}
		}
		
		cout<<all<<'\n';
	}
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
