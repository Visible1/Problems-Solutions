#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
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
ifstream in;
ofstream out;

struct pt {
    ll x, y;
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

int orientation(pt a, pt b, pt c) {
    ll v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, vector<pt>& taken, vector<pt>& left, bool include_collinear) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return pair<ll,ll>{a.y, a.x} < pair<ll,ll>{b.y, b.x};
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear)){
            left.pb(st.back());
            st.pop_back();
        }
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    taken = st;
    
}
 
void deal(){
    ll n;
    cin>>n;

    vector<pt> all(n);

    fori(n){
        cin>>all[i].x>>all[i].y;
    }

    vector<pt> taken1, left1, taken2, left2;

    convex_hull(all, taken1, left1, false);
    

    if(!left1.empty()){
        convex_hull(left1, taken2, left2, false);
    }

    bool ans = 0;

    if(taken1.size() > 3 || taken2.size() > 3){
        ans = 1;
    }
    else{
        if(taken1.size() == 3){
            if(taken2.size() == 3){
                ans = 1;
            }
            else if(taken2.size() == 2){
                vector<pt> test = taken1;
                for(auto& el : taken2){
                    test.pb(el);
                }

                fori(5){
                    vector<pt> cur = test;
                    cur.erase(cur.begin() + i);

                    vector<pt> curTake, curLeft;
                    convex_hull(cur, curTake, curLeft, false);

                    if(curTake.size() == 4){
                        ans = 1;
                    }
                }

            }
        }
    }

    if(ans){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
