/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/
 
#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define forx(v) for(int x=0; x<v; x++)
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define mt make_tuple
#define lll __int128
// #define cout out
// #define cin in
const ll INF = 1e9;
ll inf = (ll)pow(10, 18) + 10;
ll modulo = 998244353;
double eps = 1e-10;
// ifstream in;
ofstream out;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void deal(){
      ll n;
      cin>>n;
      vector<ll> arr(n);
      fori(n){
            cin>>arr[i];
      }
      sort(arr.rbegin(), arr.rend());
      ll pv = arr[0];
      ll lst = 0;
      ll s = 0;
      for(ll i = 1; i<n; i++){
            s+=arr[i];
            if(s >= pv){
                  pv += s;
                  lst = i;
                  s  = 0;
            }
      }
      cout<<lst+1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}
