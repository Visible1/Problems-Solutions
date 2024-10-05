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

struct srt{
	const bool operator()(const pair<ll, ll>& a,const pair<ll, ll>& b) const{
		return a.ss > b.ss;
	}
};

void deal(){
	ll a, b, c, n;
	cin>>n>>a>>b>>c;
	vector<ll> th({a, b, c});
	sort(th.begin(), th.end());
	a = th[0], b = th[1], c = th[2];
	
	ll gc = __gcd(__gcd(a, b), c);
	
	a /= gc, b /= gc, c/=gc;
	
	if(n % gc != 0){
		n /= gc;
		n++;
	}
	else{
		n /= gc;
	}
	
	vector<ll> tim(a, inf);
	tim[0] = 0;
	
	priority_queue<pair<ll, ll> , vector<pair<ll,ll> > , srt> pq;
	
	pq.push(mp(0, 0));
	
	while(!pq.empty()){
		auto tp = pq.top();
		pq.pop();
		
		ll hd = tp.ff;
		
		ll to1 = (hd + b) % a;
		if(tim[hd] + b < tim[to1]){
			tim[to1] = tim[hd] + b;
			pq.push(mp(to1, tim[to1]));
		}
		
		ll to2 = (hd + c) % a;
		if(tim[hd] + c < tim[to2]){
			tim[to2] = tim[hd] + c;
			pq.push(mp(to2, tim[to2]));
		}	
	}
	
	ll ans = 0;
	fori(a){
	//	cout<<"tim is "<<tim[i]<<endl;
		if(n > tim[i]){
			ans += (n-1 - tim[i]) / a  + 1;
		}
	}
	
	cout<<ans;
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
