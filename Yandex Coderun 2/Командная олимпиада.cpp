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

ll slv(vector<ll>& v1, vector<ll>& v2, vector<ll>& v3){
    ll n = (ll)v1.size() - 2;

    vector<ll> p1(n+2, 0), s2(n+2, 0);

    for(ll i = 1; i<=n; i++){
        p1[i] = p1[i-1] + v1[i];
    }

    for(ll i = n; i>=1; i--){
        s2[i] = s2[i+1] + v2[i];
    }

    vector<ll> m12(n+2, 0);
    ll minSum = inf;


    for(ll i = 1; i<=n; i++){
        m12[i] = minSum - s2[i+1];
        minSum = min(minSum, p1[i] + s2[i+1]);
    }

    vector<ll> s3(n+2, 0);
    for(ll i = n; i>=1; i--){
        s3[i] = s3[i+1] + v3[i];
    }

    ll ans = inf;

    for(ll i = 2; i<=n-1; i++){
        ans = min(ans, m12[i] + s3[i+1]);
    }

    return ans;
}


 
void deal(){
    ll n;
    cin>>n;
    
    vector<ll> v1(n+2, 0), v2(n+2, 0), v3(n+2, 0);

   
    for(ll i = 1; i<=n; i++){
        cin>>v1[i];
    }

    for(ll i = 1; i<=n; i++){
        cin>>v2[i];
    }

    for(ll i = 1; i<=n; i++){
        cin>>v3[i];
    }

    ll ans = min({slv(v1, v2, v3), slv(v1, v3, v2), slv(v2, v1, v3), 
                slv(v2, v3, v1), slv(v3, v1, v2), slv(v3, v2, v1)});

    cout<<ans;

}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
