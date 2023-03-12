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
#define ll long long 
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = 1000007;
double eps = 1e-6;
ifstream in;
ofstream out;

#define MAX 2020

ll ans = 0;

void dfs(ll hd, vector<vector<ll> >& tr, vector<ll>& tin, vector<ll>& tout, ll& tim){
      tin[hd] = tim;
      for(auto& hr : tr[hd]){
            ++tim;
            dfs(hr, tr, tin , tout, tim);
      }
      tout[hd] = tim;
}

void deal(){
	ll n;
      cin>>n;
      vector<vector<ll> > arr(n+1, vector<ll>(5));
      fori(n){
            forj(5){
                  cin>>arr[i+1][j];
            }
      }
      vector<vector<ll> > tr(n+1);
      vector<ll> tot(n+1, 0);
      
      vector<vector<ll> > child(n+1);
      
      for(ll j = 1; j<=n; j++){
            ll mnrd = inf, id = 0;
            
            for(ll i = 1; i<=n; i++){
                  ll x2 = arr[j][0], y2 = arr[j][1] , r2 = arr[j][2];
                  ll x1 = arr[i][0], y1 = arr[i][1], r1 = arr[i][2];
                  if(i == j){
                        continue;
                  }
                  ll dt =  (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                  if(r1 >= r2 && dt <= (r1 - r2) * (r1 - r2)){
                        tot[j]++;
                        child[i].pb(j);
                        if(r1 < mnrd){
                              mnrd = r1, id = i;
                        }
                  }
            }
            
            tr[id].pb(j);
      }
      vector<ll> tin(n+1), tout(n+1);
      ll tim = 0;
      dfs(0, tr, tin , tout, tim);
      
      set<ll> block;
      vector<ll> sira;
      vector<ll> minAllow(n+1, 0);
      vector<vector<bool> > good(n+1, vector<bool>(n+1, 0));
      
      ll ans = 0;
      
      for(ll i = 1; i<=n; i++){
            ll mxvl = 0;
            ll vl = 0;
            ll ai = arr[i][3], bi= arr[i][4];
            
            ll mnj = 0;
            for(ll j = 1; j<=tot[i]; j++){
                  if(j & 1){
                        vl += ai;
                  }
                  else{
                        vl += bi;
                  }
                  if(vl > mxvl){
                        mxvl = vl;
                        mnj = j;
                  }
            }
            
            minAllow[i] = mnj;
            vl = 0;
            
            for(ll j = 0; j<=tot[i]; j++){
                  if(vl == mxvl){
                        good[i][j] = 1;
                  }
                  if(j % 2 == 0){
                        vl += ai;
                  }
                  else{
                        vl += bi;
                  }
            }
            
            
            ans += mxvl;
      }
      
      for(ll i =1; i<=n; i++){
            if(minAllow[i] == tot[i]){
                  block.insert(tin[i]);
            }
      }
      block.insert(inf);
      
      vector<bool> seen(n+1, 0);
      
      for(ll i = 1; i<=n; i++){
            ll lz = -1;
            for(ll j = 1; j<=n; j++){
                  if(seen[j] || !good[j][tot[j]]){
                        continue;
                  }
                  ll s1 = tin[j] + 1;
                  auto it = block.lower_bound(s1);
                  if(*it > tout[j]){
                        lz = j;
                        break;
                  }
            }
        //    cout<<"lz is "<<lz<<endl;
            seen[lz] = 1;
            sira.pb(lz);
            
            auto it = block.find(tin[lz]);
            if(it != block.end()){
                  block.erase(it);
            }
            
            
            
            for(auto& el : child[lz]){
                  if(!seen[el]){
                        --tot[el];
                        if(minAllow[el] == tot[el]){
                              block.insert(tin[el]);
                        }
                  }
            }
      }
      
      assert((ll)sira.size() == n);
      
      cout<<ans<<'\n';
      for(auto& el : sira){
            cout<<el<<' ';
      }
      
}
 

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

