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
	vector<vector<pair<char, ll> > > all(3);
	
	fori(3){
		string a;
		cin>>a;
		ll n = a.length();
		for(ll j = 0; j<n ;){
			ll k = j;
			while(k<n && a[k] == a[j]){
				++k;
			}
			all[i].pb(mp(a[j], k-j));
			j = k;
		}
	}
	
	if(all[0].size() == all[1].size() && all[1].size() == all[2].size()){
		
		string ans = "";
		
		fori((ll)all[0].size()){
			if(all[0][i].ff == all[1][i].ff && all[0][i].ff == all[2][i].ff){
				vector<ll> th({all[0][i].ss, all[1][i].ss, all[2][i].ss});
				sort(th.begin(), th.end());
				
				
				forj(th[1]){
					ans += all[0][i].ff;
				}
			}
			else{
				cout<<"IMPOSSIBLE";
				return;
			}
		}
		
		
		cout<<ans;
	}
	else{
		cout<<"IMPOSSIBLE";
		return;
	}
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
