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

#define MAX 1'000'010
ll dv[MAX];

void pre(){
    for(ll i = 1; i<MAX; i++){
        for(ll j=i; j<MAX; j+=i){
            dv[j]++;
        }
    }
}
 
void deal(){
    pre();

    ll n;
    cin>>n;

    ll ans = 0, tot = 0;

    fori(n+1){
        if(dv[i] >= dv[ans]){
            ans = i;
        }
    }

    cout<<ans<<" "<<dv[ans]<<'\n';
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
