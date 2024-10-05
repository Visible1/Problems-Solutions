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

ll conv(string a){
	ll a1 = ((a[0] - '0')*10 + (a[1] - '0'))* 60 +
		(a[3] - '0')*10 + (a[4] - '0');
	return a1;
}

pair<ll, ll> getVal(string a, string b){
	return mp(conv(a), conv(b));
}

string getStr(ll vl){
	string s = to_string(vl);
	if(vl < 10){
		s = "0" + s;
	}
	return s;
}


void deal(){	
	string a, b, c, d;
	cin>>a>>b>>c>>d;
	auto a1 = getVal(a, c);
	auto a2 = getVal(b, d);
	
	// a1.ff + b * a1.ss = a2.ff + c * a2.ss
	
	vector<string> all  ({"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", 
	"Thursday", "Friday" });
	
	for(ll i = 1; i<(ll)1e8; i++){
		ll val = a1.ff + i * a1.ss;
		ll j = (val - a2.ff) / a2.ss;
		if(j>0 && a2.ff + j * a2.ss == val ){
			// gg
			// time is val minutes
			ll days = val / (24 * 60);
			
			ll hrs = (val - days * 24 * 60) / 60;
			
			ll mns = (val - days * 24 * 60 - hrs * 60);
			
			cout<<all[days%7]<<'\n';
			
			string v1 = getStr(hrs);
			string v2 = getStr(mns);
			
			cout<<v1<<":"<<v2<<'\n';
			
			return;
		}
	}
	
	cout<<"Never";
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
