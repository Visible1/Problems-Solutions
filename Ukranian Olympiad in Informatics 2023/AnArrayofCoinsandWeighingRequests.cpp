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
#define lll __int128
#define ld long double
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10, 9) + 7;
ld eps = 1e-13;
ifstream in;
ofstream out;

void prt(ll a, ll b){
      for(ll i = a; i<= b; i++){
            cout<<i;
            if(i!= b){
                  cout<<' ';
            }
      }
}


bool dbg = 0;


void deal(){
      ll n , k , g;
      if(!dbg){
            cin>>n>>k>>g;
      }
      else{
            k = 4;
            n = 16;
      }
      
      
      ll lo = 1, hi = n-k+1;
      
      ll cnt = 0;
      
      // we get -1 as input !!!
      
      // not because of number of queries !!!
      
      // , because invalid parameters , interesting
      // we definitely use < 16 queries !!!
      
      
      while(lo < hi){
            ++cnt;
            ll ed;
            if(k < (hi - lo + 1)/3){
                  // this case divide by 3
                  ll m1 = (lo-1) + k;
                  ll m2 = (lo-1) + (hi-lo+1)/3;
                  ll m3 = m2 + k;
                  ll m4 = m2 + (hi - lo + 1)/3;
            
                  cout<<"? "<<m2-m1+1<<' '<<m4-m3+1<<' ';
                  
                  assert(m1 >= 1);
                  
                  assert(m1 >= lo);
                  assert(m2 > m1);
                  assert(m2 <= n);
                  
                  assert(m3 > m2);
                  assert(m4 > m3);
                  assert(m4 <= n);
                  
                  prt(m1, m2);
                  cout<<' ';
                  prt(m3, m4);
                  
                  cout<<endl;
                  
                  cin>>ed;
                  
                  
                  if(ed == 0){
                        // both equal 
                        // last stack
                        lo = m4+1;
                  }
                  else if(ed == 1){
                        // left heavy, right fake
                        // mid stack
                        lo = m2+1, hi = m4;
                  }
                  else{
                        // right heavy, left fake
                        // left stack
                        hi = m2;
                  }
                  
            }
            else{
                  if(hi - lo == 1){
                        cout<<"? 1 1 "<<lo<<" "<<hi+k-1<<endl;
                        cin>>ed;
                        
                        assert(lo >= 1);
                        assert(hi + k - 1 > lo);
                        assert(hi + k - 1 <= n);
                        
                        assert(ed != 0);
                        
                        
                        if(ed == 1){
                              lo = hi;
                              // left heavy, right  fake
                        }
                        else{
                              hi = lo;
                              // right heavy, left fake
                        }
                  }
                  else{
                        ll m1 = lo + (hi-lo+1)/3 - 1;
                        ll m2 = hi - (hi - lo + 1)/3 + 1;
                        cout<<"? 1 1 "<<m1<<" "<<m2 + k-1<<endl;
                        
                        assert(m1 >= 1);
                        assert(m1 >= lo);
                        assert(m2 + k -1 <= n);
                        assert(m2 + k - 1 > m1);
                        
                        cin>>ed;
                        if(ed == 0){
                              // both heavy
                              // mid stack
                              lo = m1 + 1;
                              hi = m2 - 1;
                        }
                        else if(ed == 2){
                              // right heavy , left fake
                              hi = m1;
                        }
                        else{
                              // left heavy, right fake
                              lo = m2;
                        }
                  }
            }
            assert(cnt < 14);
            assert(ed != -1);
            if(ed == -1){
                  return;
            }
      }
      assert(lo == hi); 
      // we find wrong number 
      cout<<"! "<<lo<<endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
      
      return 0;
}
