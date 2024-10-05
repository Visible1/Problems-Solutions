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


string findNext(string a){
	ll n = a.length();
	ll s1 = 0, s2 = 0;
	fori(n/2){
		s1 += (a[i] - '0');
		s2 += (a[n-1-i] - '0');
	}
	
	if(s1 > s2){
		// s1 > s2 : good
		ll dif = s1 - s2;
		string aCopy = a;
		
		for(ll i = n-1; i >= n/2; i--){
			ll cr = min(dif, (ll)('9' - aCopy[i]));
			aCopy[i] += cr;
			dif -= cr;
		}
		return aCopy;
	}
	else{
		ll incId = -1;
		
		// s1 <= s2 : iffy
		ll dif = s2 - s1 + 1;
		// you need to decrease by dif and increase someone in front by one
		
		string aCopy = a;
		
		ll s = 0;
		ll id = n-1;
		while(id >= n/2 && s < dif){
			s += aCopy[id] - '0';
			--id;
		}
		
		while(id >= n/2 && aCopy[id] == '9'){
			--id;
		}
		
		incId = id;
		
		if(id < n/2){
			// left + 1, and right
			
			string left = "";
			string right = "";
			
			
			fori(n/2){
				left += a[i];
			}
			
			for(ll i= n/2- 1; i>=0; i--){
				if(left[i] == '9'){
					left[i] = '0';
				}
				else{
					left[i]++;
					break;
				}
			}
			
			
			right = string(n/2, '0');
			
			return findNext(left+right);
		}
		else{
			aCopy[incId]++;
			for(ll i = incId+1; i<n; i++){
				aCopy[i] = '0';
			}
			return findNext(aCopy);
		}
	}
		
}

void deal(){
	string a;
	cin>>a;
	
	ll n = a.length();
	
	if(a == string(n, '9')){
		cout<<findNext(string(n, '0'));
	}
	else{
		cout<<findNext(a)<<'\n';
	}
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
