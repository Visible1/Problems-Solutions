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

vector<bool> visited; // keeps track of which vertices are already visited

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>>& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v]){
        if (!visited[u]){
            dfs(u, adj, output);
        }
    }
    output.push_back(v);
}

// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongy_connected_components(vector<vector<int>>&  adj,
                                  vector<vector<int>>& components,
                                  vector<int> &order) {
    vector<vector<int> > adj_cond;

    int n = adj.size();
    components.clear(), adj_cond.clear();

    // order will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            dfs(i, adj, order);
        }
    }

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);


    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order){
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            sort(component.begin(), component.end());
            components.push_back(component);
            int root = component.front();
            for (auto u : component)
                roots[u] = root;
        }
    }

}

#define MAX 1'000'010

void deal(){	
    ll n, m, k;
    cin>>n>>m>>k;

    vector<vector<ll> > all(n);

    fori(k){
        ll ai, bi;
        cin>>ai>>bi;
        --ai;
        all[ai].pb(bi);
    }

    vector<vector<int> > adj(MAX);

    ll nodes = 2*m;

    fori(n){
        ll sz = all[i].size();

        // add 2*sz extra nodes

        vector<ll> wishes(sz);

        forj(sz){
            ll wj = all[i][j];
            ll wh ;
            if(wj > 0){
                wh = wj - 1; 
            }
            else{
                wh = m + (-wj - 1);
            }
            wishes[j] = wh;
        }

        for(ll j = nodes; j<nodes+sz-1; j++){
            adj[j].pb(j+1);
        }

        for(ll j = nodes+2*sz-1; j>nodes+sz; j--){
            adj[j].pb(j-1);
        }

        forj(sz){
            // map the nodes (nodes + j ) and (nodes + sz + j) to the wish j
            adj[nodes+j].pb(wishes[j]);
            adj[nodes+sz+j].pb(wishes[j]);
        }

        forj(sz){
            // if wish j is not satisfied : e.g. negation of wish j;
            ll vl = wishes[j];
            if(vl < m){
                vl += m;
            }
            else{
                vl -= m;
            }
            
            // all else has to be satisfied

            if(j + 1 < sz){
                adj[vl].pb(nodes + j + 1);
            }
            if(j - 1 >= 0){
                adj[vl].pb(nodes + sz + j - 1);
            }
        }
        nodes += 2*sz;
    }

    vector<vector<int> > comp;
    vector<int> order;


    strongy_connected_components(adj, comp, order);

    vector<ll> cId(2*m, -1); // compon

    fori((ll)comp.size()){
        for(auto& el : comp[i]){
            if(el < 2*m){
                cId[el] = i;
            }
        }
    }

    fori(m){
        if(cId[i] == cId[i+m]){
            cout<<"-1";
            return;
        }
    }

    vector<ll> ans;
    fori(m){
        if(cId[i] > cId[i + m]){
            ans.pb(i+1);
        }
    }

    cout<<ans.size()<<'\n';
    
    for(auto& el : ans){
        cout<<el<<' ';
    }

}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
