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
	string a;
	getline(cin, a);
	
	auto isLetter = [](char f){
		return (f>='A' && f<='Z') ||  (f>='a' && f<='z');
	};
	
	map<string , ll > all;
	
	fori((ll)a.length() - 1){
		if(isLetter(a[i]) && isLetter(a[i+1])){
			string cur = "";
			cur += a[i];
			cur += a[i+1];
			all[cur]++;
		}
	}
	
	ll mx = 0;
	string ans = "";
	for(auto& el : all){
		if(el.ss >= mx){
			mx = el.ss;
			ans = el.ff;
		}
	}
	
	cout<<ans;
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
