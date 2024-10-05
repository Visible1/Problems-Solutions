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

#define MAX 100


ll fkt[MAX];
ll invfkt[MAX];

ll pow_mod(ll a, ll b){
	a = a%modulo;
	ll has = 1%modulo;
	for(ll i = 62; i>-1; i--){
		has*=has;
		has%=modulo;
		if(((ll)1<<i)&b)
			has*=a, has%=modulo;
	}
	return has;
}

ll inv(ll a){
	return pow_mod(a, modulo-2);
}

ll choose(ll i, ll j){
	return fkt[i] * invfkt[j] % modulo * invfkt[i-j] % modulo;
}

vector<ll> bernoulliTop({1, 1, 1, 0, -1, 0, 1, 0, -1, 0, 5, 0, -691, 0, 7, 0, -3617, 0, 43867, 0, -174611, 0, 854513, 0, -236364091, 0, 8553103, 0, -23749461029, 0, 8615841276005, 0, -7709321041217, 0, 2577687858367, 0});
vector<ll> bernoulliBot({1, 2, 6, 1, 30, 1, 42, 1, 30, 1, 66, 1, 2730, 1, 6, 1, 510, 1, 798, 1, 330, 1, 138, 1, 2730, 1, 6, 1, 870, 1, 14322, 1, 510, 1, 6, 1, 1919190, 1, 6, 1, 13530, 1, 1806, 1, 690, 1, 282, 1, 46410, 1, 66, 1, 1590, 1, 798, 1, 870, 1, 354, 1, 56786730, 1});
vector<ll> bernoulli;


struct polynomial{
	vector<ll> vals;
	
	polynomial(){}
	polynomial(vector<ll> vn){
		vals = vn;
	}
	polynomial operator *(polynomial other){
		if(vals.empty() || other.vals.empty()){
			return polynomial();
		}
		
		auto& v1 = vals;
		auto v2 = other.vals;
		
		ll d1 = v1.size();
		ll d2 = v2.size();
		
		vector<ll> vn(d1 + d2 - 1, 0);
		
		fori(d1){
			forj(d2){
				vn[i+j] += v1[i]  * v2[j];
				vn[i+j] %= modulo;
			}
		}
		return polynomial(vn);
	}
	
	polynomial getSum(){
		if(vals.empty()){
			return polynomial();
		}
		
		// get summing polynomial from current one
		ll deg = vals.size();
		
		vector<ll> vn(deg + 1 , 0);
		
		// sum from 1 to x 
		// is 
		// for pth power = sum for r = 0 to p (1/(p+1) * (p+1 choose r) bernoulliR * x ^ (p - r + 1) )
		
		for(ll p =0; p<deg; p++){
			for(ll r = 0; r<=p; r++){
				ll fc = inv(p+1);
				fc = fc * choose(p+1, r) % modulo;
				fc = fc * bernoulli[r] % modulo;
				fc = fc * vals[p] % modulo;
				
				vn[p - r + 1] += fc;
				vn[p - r + 1] %= modulo;
			}
		}
		
		return polynomial(vn);
	}
	
	ll eval(ll x){
		x %= modulo;
		ll vl = 1;
		
		ll ans = 0;
		
		fori((ll)vals.size()){
			ans += vals[i] * vl;
			ans %= modulo;
			
			vl *= x;
			vl %= modulo;
		}
		
		return ans;
	}
	
	polynomial plug(ll val){
		// plug in (x + val) instead of x everywhere
		val = (val % modulo + modulo) % modulo;
		
		ll deg = vals.size();
		
		vector<ll> vn(deg, 0);
		
		fori(deg){
			// sum of vals[i] * (i choose j ) * x^(i-j) * val^j
			for(ll j = 0; j<=i; j++){
				ll fc = choose(i, j);
				fc = fc * pow_mod(val, j) % modulo;
				
				// dont forget about original factors
				
				fc = fc * vals[i] % modulo;
								
				vn[i-j] += fc;
				vn[i-j] %= modulo;
			}
		}
		
		return polynomial(vn);
	}
	
	polynomial negate(){
		ll deg = vals.size();
		
		vector<ll> vn(deg, 0);
		
		fori(deg){
			vn[i] = (modulo - vals[i]) % modulo;
		}
		
		return polynomial(vn);
	}
	
	void add(ll vl){
		// add vl to the a0 , where a0 is coefficient of x^0
		if(!vals.empty()){
			vals[0] += vl;
			vals[0] %= modulo;
		}
		else{
			vals = vector<ll>({vl});
		}
	}
	
	void display(){
		cout<<endl<<endl<<" displaying vals "<<endl;
		fori((ll)vals.size()){
			cout<<vals[i]<<' ';
		}
		cout<<endl<<endl<<endl;
	}
	
};


ll lefLim[MAX], rigLim[MAX];



void pre(){
	ll mn = min(bernoulliTop.size(), bernoulliBot.size());
	fori(mn){
		ll v1 = bernoulliTop[i];
		ll v2 = bernoulliBot[i];
		v1 = (v1 % modulo + modulo) % modulo;
		v2 = (v2 % modulo + modulo) % modulo;
		
		bernoulli.pb(v1 * inv(v2) % modulo);
	}
	
	fkt[0] = 1;
	for(ll i = 1; i<MAX; i++){
		fkt[i] = fkt[i-1] * i % modulo;
	}
	
	invfkt[MAX-1] = inv(fkt[MAX-1]);	
	for(ll i = MAX-2; i>=0; i--){
		invfkt[i] = invfkt[i+1] * (i+1) % modulo;
	}
	
	fori(MAX){
		lefLim[i] = -1;
		rigLim[i] = -1;
	}
}


ll ty[MAX];
// 0 = it is a root, 
// 1 = it is limited from above by parent
// 2 = it is limited from below by parent

vector<pair<ll,ll> > g[MAX];
// (hd, ty) , 
// ty = 1 it is limited from above by us
// ty = 2 it is limited from below by us

// !!!  Al go rithm  !!!  : 

// merge value of children who are already in the form of
// "if my parent's value is x what is the total number of loops i'll run"

// merge into a sorted vector of pairs of long longs and polynomials
// where value defines the limit of range of polynomial meaning
// (vi, pi) up until <= vi use polynomial pi, etc.

// now apply the limit of node itself : is it limited from above , below ?
// if both find answers,
// if one, then put zero polynomial where necessary

// now calculate the sums according to our parent, get sum polynomial
// for each one of the range polynomials, and apply function as necessary
// e.g. are we limited from below parent or from above ? so modify our sum
// polynomial accordingly to get it ready for parent !!!!

// so final forms of polynomials is p(x) = if parent value is x how many
// times in total will my loops run 

#define functionStack  vector<pair<ll, polynomial> >


void applyLimits(ll lef, ll rig, functionStack& all){
	if(lef != -1){
		while(all[0].ff < lef){
			all.erase(all.begin());
		}
		
		all.insert(all.begin(), mp(lef-1, polynomial()));
	}
	if(rig != -1){
		polynomial save;
		
		while(!all.empty() && all.back().ff > rig){
			save = all.back().ss;
			all.erase(all.end() - 1);
		}
		
		if(save.vals.size() != 0){
			if(all.empty() || all.back().ff != rig){
				all.pb(mp(rig, save));
			}
		}
		
		all.pb(mp(inf, polynomial()));
	}
}

functionStack getSumPol(functionStack all){
	// transform it to get sum polynomials
	
	functionStack sumPol;
	for(ll i = 0; i<(ll)all.size(); i++){
		auto cur = all[i];
		auto yeni = cur.ss.getSum();
		sumPol.pb(mp(cur.ff, yeni));
	}
	
	return sumPol;
}

functionStack dfs(ll hd, vector<vector<ll> >& g){
	
//	cout<<"!!! entering  !!!!  "<<hd<<endl;
	
	functionStack cur({mp (inf, polynomial(vector<ll>({1})) ) }); 
	
	vector<functionStack> all(1, cur);
	
	
	for(auto hr : g[hd]){
		functionStack other = dfs(hr, g);
		
		all.pb(other);
	}
	
	set<ll> indexes;
	
	fori((ll)all.size()){
		for(auto& el : all[i]){
			indexes.insert(el.ff);
		}
	}
	
	functionStack toRet;
	
	while(!indexes.empty()){
		auto val = *indexes.begin();
		indexes.erase(indexes.begin());
		
		polynomial cur(vector<ll>({1}));
		
		for(auto& pol : all){
			for(auto& lim : pol){
				if(lim.ff >= val){
					cur = cur * lim.ss;
					break;
				}
			}
		}
		
		toRet.pb(mp(val, cur));
	}
	
	
	if(ty[hd] == 0){
		// evaluate
		assert(lefLim[hd] != -1);
		assert(rigLim[hd] != -1);
		
		applyLimits(lefLim[hd], rigLim[hd], toRet);
		
		toRet = getSumPol(toRet);
		
		ll ans = 0;
		
		for(ll i = 0; i<(ll)toRet.size(); i++){
			auto cur = toRet[i];
			ll rigEval = cur.ss.eval(cur.ff);
			ll lefEval = 0;
			
			
			if(i != 0){
				ll pv = toRet[i-1].ff;
				lefEval = cur.ss.eval(pv);
			}
			
			ans += rigEval - lefEval;
			ans = (ans%modulo + modulo) % modulo;
		}
		
		toRet = functionStack( { mp(ans, polynomial()) } );
	}
	else if(ty[hd] == 1){
		// our value <= parent value
		// we have to be limited from below by value
		assert(lefLim[hd] != -1);
		assert(rigLim[hd] == -1);
		
		applyLimits(lefLim[hd], rigLim[hd], toRet);
		
		toRet = getSumPol(toRet);
		ll add = 0;

		for(ll i = 0; i<(ll)toRet.size(); i++){
			auto& cur = toRet[i];
			ll lefEval = 0;
			if(i != 0){
				ll pv = toRet[i-1].ff;
				lefEval = cur.ss.eval(pv);
			}
			ll rigEval = cur.ss.eval(cur.ff);
			
			
			add -= lefEval;
			add = (add%modulo + modulo)%modulo;
			
			cur.ss.add(add);
			
			add += rigEval;
			add = add % modulo;
			
		}
		
	}
	else{
		// our value >= parent value
		// we have to be limited from above by value
		assert(lefLim[hd] == -1);
		assert(rigLim[hd] != -1);
		
		applyLimits(lefLim[hd], rigLim[hd], toRet);
		
		toRet = getSumPol(toRet);
		
		
		ll add = 0;
		
		for(ll i = (ll)toRet.size() - 1; i>=0; i--){
			auto& cur = toRet[i];
			ll lefEval = 0;
			if(i != 0){
				ll pv = toRet[i-1].ff;
				lefEval = cur.ss.eval(pv);
			}
			ll rigEval = cur.ss.eval(cur.ff);
			
			
			add += rigEval;
			add = add % modulo;
			
			cur.ss = cur.ss.plug(-1);
			
			cur.ss = cur.ss.negate();
			
			cur.ss.add(add);
			
			add -= lefEval;
			add = (add % modulo + modulo) % modulo;
		}
		
	}
	
	
	
	auto displayFuncStack = [&](){
		for(ll i = 0; i<(ll)toRet.size(); i++){
			auto cur = toRet[i];
			cout<<"current limit "<<cur.ff<<endl;
			cout<<"polynomial is "<<endl;
			cur.ss.display();
			cout<<endl;
			
		}
	};
	
	return toRet;
}


void testSum(){
	polynomial a(vector<ll>({-4, 1}));
	
	polynomial s1 = a.getSum();
	
	s1.display();
	
	cout<<s1.eval(3) - modulo<<endl;
	cout<<s1.eval(1) - modulo<<endl;
}

void testPlug(){
	polynomial a(vector<ll>({-4, 1}));
	
	polynomial s1 = a.getSum();
	
	s1.display();
	
	s1 = s1.plug(-1);
	
	s1.display();
	
}

void deal(){
	pre();
	
	ll n;
	cin>>n;
	
	vector<vector<ll> > g(n);
	
	fori(n){
		string a, b;
		cin>>a>>b;
		if(a[0]>='a' && a[0]<='z'){
			ty[i] = 2;
			rigLim[i] = stoll(b);
			ll pr = (a[0] - 'a');
			
		//	cout<<pr<<" -> "<<i<<endl;
			
			g[pr].pb(i);
		}
		else if(b[0] >= 'a' && b[0]<='z'){
			ty[i] = 1;
			lefLim[i] = stoll(a);
			ll pr = b[0] - 'a';
			
		//	cout<<pr<<" -> "<<i<<endl;
			
			g[pr].pb(i);
		}
		else{
		//	cout<<i<<" will be root "<<endl;
			
			lefLim[i] = stoll(a) , rigLim[i] = stoll(b);
		}
	}
	
	ll ans = 1;
	
	fori(n){
		if(!ty[i]){
		//	cout<<i<<" is root "<<endl;
			auto cur = dfs(i, g);
			ans *= cur[0].ff;
			ans %= modulo;
		}
	}
	
	cout<<ans;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
