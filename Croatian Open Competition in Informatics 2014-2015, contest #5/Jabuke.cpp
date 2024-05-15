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

void deal(){
    ll n, m;
    cin>>n>>m;
    
    vector<vector<char> > arr(n, vector<char>(m));
    
    fori(n){
        forj(m){
            cin>>arr[i][j];
        }
    }
    
    vector<vector<ll> > lc(n, vector<ll>(m)), rc(n, vector<ll>(m));
    
    
    auto updRow = [] (ll i, vector<vector<char> >& arr, vector<vector<ll> >& lc,
        vector<vector<ll> >& rc){
        ll m = arr[i].size();   
        
        ll pv = -1;
        forj(m){
            if(arr[i][j] == 'x'){
                pv = j;
            }
            lc[i][j] = pv;
        }
        
        pv = -1;
        for(ll j = m-1; j>=0; j--){
            if(arr[i][j] == 'x'){
                pv = j;
            }
            rc[i][j] = pv;
        }
    };
    
    fori(n){
        updRow(i, arr, lc, rc);
    }
    
    ll g;
    cin>>g;
    forl(g){
        ll xi, yi;
        cin>>xi>>yi;
        --xi, --yi;
        
        ll best = inf;
        
        auto upd = [](ll x1, ll y1, ll xi, ll yi, ll& best){
            if(y1 != -1){
                best = min(best, (x1 - xi) * (x1 - xi) + (y1 - yi) * (y1- yi));
            }
        };
        
        
        for(ll i = 0; i<n; i++){
            upd(i, lc[i][yi], xi, yi, best);
            upd(i, rc[i][yi], xi, yi, best);
        }
        
        arr[xi][yi] = 'x';
        
        updRow(xi, arr, lc, rc);
        
        cout<<best<<'\n';
    }
    
    
    
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}

