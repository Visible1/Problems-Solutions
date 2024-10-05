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

void deal(){
	ll n;
	cin>>n;
	vector<ll> arr(n);
	fori(n){
		cin>>arr[i];
	}
	
	ll pr;
	cin>>pr;
	vector<bool> have(n, 0);
	
	fori(4){
		ll ed;
		cin>>ed;
		--ed;
		have[ed] = 1;
	}
	
	ll k;
	cin>>k;
	
	vector<ll> tot(n, 0);
	
	fori(k){
		ll ed;
		cin>>ed;
		--ed;
		tot[ed]++;
	}
	
	ll mn = inf;
	
	for(ll i = 0 ; i <22; i++){
		ll cur = i * pr;
		
		forj(n){
			ll left = tot[j];
			if(have[j]){
				left = max(0ll, left - i);
			}
			
			cur += left * arr[j];
		}
		
		
		mn = min(mn, cur);
	}
	
	
	cout<<mn;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
