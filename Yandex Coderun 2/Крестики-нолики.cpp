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
	ll n, m;
	cin>>n>>m;
	
	vector<vector<char> > arr(n, vector<char>(m));
	
	fori(n){
		forj(m){
			cin>>arr[i][j];
		}
	}
	
	ll dx[4] = {0, 1, 1, 1};
	ll dy[4] = {1, 0, -1, 1};
		
	fori(n){
		forj(m){
			char c = arr[i][j];
			if(c != '.'){
				fork(4){
					bool gg = 1;
					forz(5){
						ll x1 = i + dx[k] * z;
						ll y1 = j + dy[k] * z;
						if(x1 < n && y1 >= 0 && y1 < m && arr[x1][y1] == c){
							// good
						}
						else{
							gg = 0;
						}
					}
					if(gg){
						cout<<"Yes";
						return;
					}
				}
			}
		}
	}
	
	
	cout<<"No";
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
