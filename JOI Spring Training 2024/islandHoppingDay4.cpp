#include "island.h"
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

struct infoCity{
      ll add;
      map<ll, ll> info; // [city we started from, time it took]    
};

// pa)
// dfs nodes are technically roads, might have to query multiple nodes then

// if number of queries for some level / node is > sqrt(q) then merge all 
// infoCity for that level / node and do query later ; otherwise just per query
// just query all the related roads / nodes.  do some sqrt decomposition

// pb) 
// take node N, make all of its direct children terminal
// (e.g. figure out all their outgoing edges), then make N terminal
// take node N-1 do same thing etc. etc.

// so take next biggest node in line , 
// a) it is terminated (all of its children have been found) :
//     good , now check each child and see whether they are terminated, if not, terminate them
// b) it is not terminated :
//      find each child of it and terminate (if not terminated)
//      each child before terminating the biggest node itself
//      note : the biggest node will be terminated !!when!! the next closest node in line
//          is someone that is at distance 2 from the biggest node


void solve(int N, int L){
      ll n = N;
      vector<ll> all({0});
      fori(n-1){
            ll cur = query(1, i+1);
            --cur;
            all.pb(cur);
      }
      
      vector<ll> par(n, -1);
      vector<ll> pl(n, -1);
      
      fori(n){
            pl[all[i]] = i;
      }
      
      for(ll i=1; i<n; i++){
            ll hd = all[i];
            if(par[hd] == -1){
                  for(ll j = 1;  ;j++){
                        ll cur = query(hd+1, j);
                        --cur;
                        if(pl[cur] < pl[hd]){
                              par[hd] = cur;
                              break;
                        }
                        else{
                              par[cur] = hd;
                        }
                  }
            }
      }
      
      for(ll i = 1; i<n; i++){
            ll hd = all[i];
            answer(hd+1, par[hd] + 1);
      }
}
