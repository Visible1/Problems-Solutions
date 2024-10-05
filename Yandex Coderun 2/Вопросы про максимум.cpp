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

#define MAX 10'010


void deal(){
	
	ll n , q;
	cin>>n>>q;
	
	
	
	ll chunkSize = 100;
	ll chunkCount = n/chunkSize + 10;
	
	vector<bitset<MAX> > chunks(chunkCount);
	
	vector<vector<ll> > extra(n);
	
	fori(chunkCount){
		chunks[i][0] = 1;
	}
	
	fori(q){
		ll q1, q2, vi;
		cin>>q1>>q2>>vi;
		--q1, --q2;
		ll li = q1, ri  =q2;
		
		while(li % chunkSize != 0 && li <= ri){
			extra[li].pb(vi);
			++li;
		}
		
		while(li + chunkSize - 1 <= ri){
			ll wh = li / chunkSize;
			chunks[wh] |= (chunks[wh] << vi);
			li += chunkSize;
		}
		
		while(li <= ri){
			extra[li].pb(vi);
			li++;
		}
	}
	
	auto ans = chunks[0];
	
	fori(n){
		auto cur = chunks[i / chunkSize];
		
		for(auto& el : extra[i]){
			cur |= (cur << el);
		}
		
		ans |= cur;
	}
	
	vector<ll> res;
	
	for(ll i = 1; i<=n; i++){
		if(ans[i]){
			res.pb(i);
		}
	}
	
	cout<<res.size()<<'\n';
	
	for(auto& el : res){
		cout<<el<<' ';
	}
	
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
