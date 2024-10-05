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
	fori(n){
		string a;
		cin>>a;
	}
	
	ll m;
	cin>>m;
	
	pair<ll, ll> pv = mp(0, 0);
	
	map<string, ll> all;
	
	
	string s;
	getline(cin, s);
	
	fori(m){
		getline(cin, s);
		
		string a2 = "";
		
		ll v1 = 0, v2 = 0;
		
		ll len = s.length();
		
		for(ll j =0; j<len ;){
			while(s[j] != ':'){
				v1 *= 10;
				v1 += s[j] -'0';
				++j;
			}
			++j;
			
			while(s[j]!=' '){
				v2 *= 10;
				v2 += s[j] - '0';
				++j;
			}
			++j;
			
			while(j < len){
				a2 += s[j];
				++j;
			}
		}
		
		ll dif = v1 - pv.ff + v2 - pv.ss;
		
		all[a2]+=dif;
		
		pv = mp(v1 , v2);
		
	}
	
	ll mx = 0;
	string wh = "";
	
	
	for(auto& el : all){
		if(el.ss >= mx){
			mx = el.ss;
			wh = el.ff;
		}
	}
	
	cout<<wh<<" "<<mx;
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
