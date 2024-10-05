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

const ll mxH = 200'010; // how big hashed values can get
const ll alp = 100;     // number of different letters

vector<ll> getHashes(string& a, vector<ll>& pv, ll window, ll mod){
//    cout<<"getting hashes "<<a<<" "<<mod<<endl;


    // for sizes of window
    ll len = a.length();

    vector<ll> ans(len - window + 1, 0);

    vector<ll> lst(alp, -1); // last occurence of each letter
    vector<ll> vals(len, 0);    // what is the value stored at each index
    ll s = 0;

    fori(len){
        if(i >= window){
            // erase old value
            if(vals[i-window] != 0){
                s -= vals[i-window] * pv[window-1];
                s = ((s % mod) + mod ) % mod;
            }
        }

//        cout<<"val is "<<s<<endl;
        
        char c = a[i];
        ll vl = (c - 30);

        s = (s * mxH) % mod;

        ll wh = lst[vl];
        if(wh != -1 && wh > i - window){
            ll curv =  (i - wh) * pv[i-wh] % mod;
            vals[wh] = (i - wh);    // save that some value was added here

            s = (s + curv) % mod;
        }
        lst[vl] = i;

//        cout<<"value after index i: "<<i<<"   is "<<s<<endl;

        if(i + 1 >= window){
            // add to vector "ans"
            ans[i+1-window] = s; 
        }
    }

    return ans;
}

vector<bool> allMatches(string& a, string& b, ll mod){
    ll l1 = a.length(), l2 = b.length();

    vector<ll> pv(l1 + 10, 0); // mxH ^ i % mod

    pv[0] = 1;
    for(ll i = 1; i<l1+10; i++){
        pv[i] = pv[i-1] * mxH % mod;
    }

    vector<ll> hA = getHashes(a, pv, l2, mod);
    vector<ll> hB = getHashes(b, pv, l2, mod);

    vector<bool> ret(hA.size(), 0);
    fori((ll)hA.size()){
        if(hA[i] == hB[0]){
            ret[i] = 1;
        }
    }

    return ret;
}

void deal(){	
	string a, b;
    cin>>a>>b;

    vector<ll> pool({(ll)1e9+7, (ll)1e9 + 9});

    vector<bool> all((ll)a.length() - (ll)b.length() + 1, 1);

    for(auto& el : pool){
    //    cout<<el<<endl;
        vector<bool> cur = allMatches(a, b, el);
        fori((ll)cur.size()){
            all[i] = (all[i] && cur[i]);
        }
    }


    ll ans = 0;
    for(auto el : all){
        ans += el;
    }
    cout<<ans<<'\n';

    fori((ll)all.size()){
        if(all[i]){
            cout<<i+1<<' ';
        }
    }

}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
