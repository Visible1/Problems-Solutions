
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
#define chunkSize 350
#define chunkCount MAX / chunkSize


void recalc(vector<ll>& arr, vector<ll>& mlt, ll num){
	ll n = arr.size();
	mlt[num] = 1;
	for(ll i = num*chunkSize; i< min((num+1)*chunkSize , n) ; i++){
		mlt[num] *= arr[i];
		mlt[num] %= modulo;
	}
}

void deal(){	
	ll n;
	cin>>n;
	
	vector<ll> arr(n);
	fori(n){
		cin>>arr[i];
	}
	
	vector<ll> mlt(chunkCount, 1);
	
	for(ll i = 0; i*chunkSize < n ; i++){
		recalc(arr, mlt, i);
	}
	
	ll q;
	cin>>q;
	
	
	forl(q){
		ll ty, q1, q2;
		cin>>ty>>q1>>q2;
		--q1, --q2;
		if(ty == 1){
			ll li = q1, ri = q2;
			
			ll ans = 1;
			while(li % chunkSize != 0 && li <= ri){
				ans *= arr[li];
				ans %= modulo;
				li ++;
			}
			
			while(li + chunkSize <= ri){
				ans *= mlt[li/chunkSize];
				ans %= modulo;
				li += chunkSize;
			}
			
			while(li <= ri){
				ans *= arr[li];
				ans %= modulo;
				li++;
			}
			
			cout<<ans<<'\n';
		}
		else{
			ll li = q1, ri = q2;
			
			ll pv = -1;
			vector<ll> saved;
			while(li <= ri){
				ll cr = li / chunkSize;
				if(cr != pv){
					pv = cr;
					saved.pb(pv);
				}
				arr[li]++;
				li++;
			}
			
			for(auto& el : saved){
				recalc(arr, mlt, el);
			}
		}
	}
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
