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
// #define cout out
// #define cin in
ll inf = (ll)pow(10,18);
ll modulo = 998244353;
ld eps = 1e-13;
ifstream in;
ofstream out;


#define MAX 200'200
ll tot[MAX];

struct srt{
      const bool operator()(const pair<ll, ll>& a, const pair<ll,ll>& b) const{
            if(a.ff == b.ff){
                  return a.ss < b.ss;
            }
            return a.ff > b.ff;
      }    
};

void dfs(ll hd, vector<vector<ll> >& g, vector<ll>& ls, vector<ll>& nm,
            vector<bool>& md, set<pair<ll, ll>, srt>& arr, vector<ll>& cnts){
      if(md[hd]){
            auto it = arr.begin();
            ll wh = (*it).ss;
            
       //     cout<<wh<<" is the winner "<<endl;
            
            tot[wh]++;
      }
      
      for(auto& hr : g[hd]){
            ll dif = ls[hd] - ls[hr];
            ll player = nm[hd];
            
    //        cout<<hr<<" lost to "<<hd<<" so adding "<<dif<<endl;
            
            arr.erase(arr.find(mp(cnts[player], player)));
            cnts[player] += dif;
            arr.insert(mp(cnts[player], player));
            
            dfs(hr, g, ls, nm, md, arr, cnts);
      
            arr.erase(arr.find(mp(cnts[player], player)));
            cnts[player] -= dif;
            arr.insert(mp(cnts[player], player));
            
  //          cout<<"undoing "<<hr<<" lost to "<<hd<<" so adding "<<dif<<endl;

      }
}

void deal(){
      ll n, m;
      cin>>n>>m;
      vector<ll> lst(n, -1); // last mention for the node
       
      
      vector<pair<ll, ll> > all(m);
      fori(m){
            cin>>all[i].ff>>all[i].ss;
      }
      
      ll nod = 0;
      vector<vector<ll> > g(2*m+1);
      vector<ll> loss(2*m+1, m), nm(2*m+1, 0);
      vector<bool> med(2*m + 1, 0);
      
      for(ll i = m-1; i>=0 ; i--){
            ll x = all[i].ff, y = all[i].ss;
            if(lst[x] == -1){
                  nod++;
                  lst[x] = nod;
                  g[0].pb(nod);
                  
                  loss[lst[x]] = m;
                  nm[lst[x]] = x;
                  
            }
            
            nod++;
            lst[y] = nod;
            
            loss[lst[y]] = i;
            nm[lst[y]] = y;
            med[lst[y]] = 1; 
            
            g[lst[x]].pb(lst[y]);
      }
      
      set<pair<ll, ll>, srt> arr;
      vector<ll> cnts(n, 0);
      
      fori(n){
            arr.insert(mp(0, i));
      }
      
      dfs(0, g, loss, nm, med, arr, cnts);
      
      fori(n){
            cout<<tot[i]<<' ';
      }
      
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
