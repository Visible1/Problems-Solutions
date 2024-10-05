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
	
	ll n , m;
	cin>>n>>m;
	
	ll liml, limr;
	cin>>liml>>limr;
	
	vector<pair<ll, ll> > arr1, arr2;
	
	fori(n){
		ll ai, bi;
		cin>>ai>>bi;
		arr1.pb(mp(ai, bi));
	}
	
	fori(m){
		ll ai, bi;
		cin>>ai>>bi;
		arr2.pb(mp(ai, bi));
	}
	
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	
	
	set<ll> check;
	check.insert(liml);
	
	ll totalDif = arr2.back().ss - arr2[0].ff;
	
	check.insert(limr - totalDif);
	
	
	
	fori(m){
		forj(n){
			// ith is moved to be just before jth
			// a2[i].ss = a1[j].ff 
			ll dif =  arr2[i].ss - arr2[0].ff;
			ll yeni = arr1[j].ff - dif;
			
			if( yeni >= liml && yeni + totalDif <= limr){
				check.insert(yeni);
			}
			
			// ith is moved to be just after jth
			// a2[i].ff = a1[j].ss
			
			dif = arr2[i].ff - arr2[0].ff;
			yeni = arr1[j].ss - dif;
			
			if(yeni >= liml && yeni + totalDif <= limr){
				check.insert(yeni);
			}
		}
	}
	
	
	ll ans = inf;
	
	for(auto& cr : check){
		
		ll cans = 0;
		ll i1 = 0, i2 = 0;
		while(i1 < n && i2 < m){
			ll a1 = arr1[i1].ff, a2 = arr1[i1].ss;
			ll b1 = arr2[i2].ff, b2 = arr2[i2].ss;
			
			b1 = (b1 - arr2[0].ff) + cr , b2 = (b2 - arr2[0].ff) + cr;
						
			if(b2 <= a2){
				// increase i2
				// kesishirler mi ?
				
				// ...... b2 .... a2
				
				if(b2 > a1){
					// .... a1 .... b2 ... a2
					// he
					if(b1 >= a1){
						// total intersection
						// .... a1 .... b1 .... b2 .... a2
						cans += b2 - b1;
					}
					else{
						// partial
						cans += b2 - a1;
					}
				}
				
				++i2;
				// else hec ne
				
			}
			else{
				// increase i1
				
				// .. a2 ... b2
				
				if(a2 > b1){
					// .... b1 ... a2 ... b2
					if(a1 >= b1){
						// ..... b1 ... a1 .... a2 ... b2
						cans += a2 - a1;
					}
					else{
						cans += a2 - b1;
					}
				}
				++i1;
			}
			
		}
		
		ans = min(ans, cans);
	}
	
	cout<<ans;
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
