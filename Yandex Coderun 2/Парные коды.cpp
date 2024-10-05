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
	ll n;
	cin>>n;
	
	ll cnt = 0;
	vector<ll> buf;
	vector<ll> dp(1<<10, 0);
	
	ll ans = 0;
	
	
	ll bufsize =  100;
	
	fori(n){
		string a;
		cin>>a;
		
		ll bt = 0;
		for(auto& f : a){
			bt |= (1<<(f-'0'));
		}	
	
		// need to add everyone who was not a  part of (subset of its inverse)
		ans += (cnt - dp[((1<<10) - 1) ^ bt ]);
		
		
		for(auto& el : buf){
			if((el & bt)!=0){
				ans++;
			}
		}
		
		buf.pb(bt);
		
		if((ll)buf.size() == bufsize){
			vector<ll> dpn(1<<10, 0);
			for(auto& el : buf){
				dpn[el]++;
			}
			
			forj(10){
				fori(1<<10){
					if(i & (1<<j)){
						dpn[i] += dpn[i ^ (1<<j)];
					}
				}
			}
			
			fori(1<<10){
				dp[i] += dpn[i];
			}
			
			buf.clear();
			cnt+=bufsize;
		}
		
	}
	
	cout<<ans;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
