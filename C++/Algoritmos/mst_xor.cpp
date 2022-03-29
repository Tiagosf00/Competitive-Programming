// omg why just 2 seconds
#include <bits/stdc++.h>
// #define int long long
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ti tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) (((a)+(b)-1)/(b))
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define dbg(msg, var) cerr << msg << " " << var << endl;
 
using namespace std;
 
const int MAX = 6e6+10;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-6;
const ld PI = acos(-1);
 
// End Template //

const int N = 2e5+10;

struct DSU {
    int n;
    map<int, int> parent;
    map<int, vi> comp;

    int find(int v) {
        if(v==parent[v])
            return v;
        return parent[v]=find(parent[v]);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if(a!=b) {
            if((int)comp[a].size()<(int)comp[b].size())
                swap(a, b);

            for(auto v: comp[b])
                comp[a].pb(v);
            comp[b].clear();
            parent[b]=a;
        }

    }
};

int trie[MAX][2];
set<int> idx[MAX];
int finish[MAX];
int nxt = 1;

void add(int s){
    int node = 0;
    for(int i=30;i>=0;i--){
        bool c = (s & (1<<i));
        if(trie[node][c] == 0)
            node = trie[node][c] = nxt++;
        else
            node = trie[node][c];
        finish[node]++;
    }
}

void remove(int s){
    int node = 0;
    for(int i=30;i>=0;i--){
        bool c = (s & (1<<i));
        node = trie[node][c];
        finish[node]--;
    }
}

int min_xor(int s){
    int node = 0;
    int ans = 0;
    for(int i=30;i>=0;i--){
        bool c = (s & (1<<i));
        if(finish[trie[node][c]] != 0)
            node = trie[node][c];
        else{
            ans ^= 1 << i;
            node = trie[node][!c];
        }
    }
    return ans;
}


int32_t main()
{sws;

    int n;
    cin >> n;
    vi x(n);
    for(int i=0;i<n;i++)
        cin >> x[i];

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    n = x.size();

    DSU dsu;

    ll mstsum = 0;

    vi pais;
    for(int i=0;i<n;i++){
        add(x[i]);
        dsu.parent[x[i]] = x[i];
        dsu.comp[x[i]].pb(x[i]);
        pais.pb(x[i]);
    }

    while((int)pais.size()!=1){
        vector<ti> edges;
        for(auto p: pais){
            vi &nodes = dsu.comp[p];
            // erase
            for(auto u: nodes) remove(u);

            // query
            ti ed = {LLINF, 0, 0};
            for(auto u: nodes){
                int xr = min_xor(u);
                ed = min(ed, {xr, u, xr^u});
            }
            edges.pb(ed);

            // add back
            for(auto u: nodes) add(u);
        }

        for(auto [xr, u, v]: edges){
            if(dsu.find(u)!=dsu.find(v)){
                // u, v -> mst
                // cout << "mst = " << u << " " << v << endl;
                mstsum += xr;
                dsu.join(u, v);
            }
        }
        vi pais2;
        for(auto p: pais)
            if(p==dsu.find(p))
                pais2.pb(p);
        swap(pais, pais2);
    }

    cout << mstsum << endl;


    return 0;
}