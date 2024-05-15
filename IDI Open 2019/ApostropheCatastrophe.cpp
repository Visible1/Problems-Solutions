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
    string a, b;
    cin>>a>>b;
    
    ll totp = 0, totn = 0;
    
    fori((ll)a.length()){
        if(a[i] == '+'){
            totp++;
        }
        else if(a[i] == '-'){
            totn++;
        }
    }
    
    if(!totp && !totn){
        if(a != b){
            cout<<"corrupted";
        }
        else{
            cout<<"<any> <any>";
        }
    }
    else{
        
        vector<pair<string, string> > ans;
        
        for(ll plen = 0;  ;plen++){
            ll len = (ll) a.length();
            ll raw = len - totp - totn;
            
            ll lenNew = raw + plen * totp ;
            
            
            ll leftLen = (ll)b.length() - lenNew;
            
            if(leftLen < 0){
                break;
            }
            
            
            if(leftLen == 0 || ( totn && leftLen % totn == 0)){
                ll nlen = 0 ;
                if(totn){
                    nlen = leftLen / totn;
                }
                
            //  cout<<"plen nlen "<<plen<<" "<<nlen<<endl;
                
                string plus = "";
                string neg = "";
                
                bool bad = 0;
                
                for(ll i = 0, j = 0; i<(ll)a.length()  ;i++){
                    if(a[i] == '+'){
                        string cur = "";
                        for(ll k = 0; k<plen; k++){
                            cur += b[j];
                            ++j;
                        }
                        
                        if(plus == ""){
                            plus = cur;
                        }
                        else{
                            if(plus != cur){
                                bad = 1;
                            }
                        }
                    }
                    else if(a[i] == '-'){
                        string cur = "";
                        for(ll k = 0; k<nlen; k++){
                            cur += b[j];
                            ++j; 
                        }
                        
                        if(neg == ""){
                            neg = cur;
                        }
                        else{
                            if(neg != cur){
                                bad = 1;
                            }
                        }
                        
                    }
                    else{
                        if(a[i] != b[j]){
                            bad = 1;
                        }
                        ++j;
                    }
                }
                
                if(!bad){
                    ans.pb(mp(plus, neg));
                }
                
                
            }
            
            if(totp == 0){
                break;
            }
        }
        
        auto print = [](string a, ll cnt){
            if(a == ""){
                if(cnt == 0){
                    cout<<"<any>";
                }
                else{
                    cout<<"<empty>";
                }
            }
            else{
                cout<<a;
            }
        };
        
        for(auto& el : ans){
            print(el.ff, totp);
            cout<<' ';
            print(el.ss, totn);
            cout<<'\n';
        }
        
        if(ans.empty()){
            cout<<"corrupted";
        }
        
    }
    
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}
