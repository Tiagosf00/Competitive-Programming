#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep1(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, a, b) for(int i=(int)a;i<(int)b;i++)
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define p_b pop_back
#define p_f pop_front
#define mp make_pair
#define MAX 100010
#define oo INT_MAX
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef vector<bool> vb;

vvi G(MAX);
vb vstd(MAX, false);

double dist(int x1, int y1, int x2, int y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void dfs(int u){
	if(vstd[u])
		return;
	vstd[u] = true;
	for(auto& v : G[u]){
		dfs(v);
	}
}

int main()
{
	
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int m, n, k;
	cin >> m >> n >> k;
	vii pts;
	vi r;
	rep1(i, k){
		int x, y, s;
		cin >> x >> y >> s;
		pts.pb(mp(x, y));
		r.pb(s);
	}

	rep1(i, k){
		rep2(j, i+1, k){
			if(i != j){
				double d = dist(pts[i].st, pts[i].nd, pts[j].st, pts[j].nd);
				if(d <= r[i]+r[j]){
					G[i].pb(j);
					G[j].pb(i);
				}
			}
		}

		if(pts[i].st - r[i] <= 0){
			G[i].pb(k+2);
			G[k+2].pb(i);
		}
		if(pts[i].st + r[i] >= m){
			G[i].pb(k);
			G[k].pb(i);
		}
		if(pts[i].nd + r[i] >= n){
			G[i].pb(k+3);
			G[k+3].pb(i);
		}
		if(pts[i].nd - r[i] <= 0){
			G[i].pb(k+1);
			G[k+1].pb(i);
		}
	}

	bool poss = true;

	dfs(k+2);
	if(vstd[k+1] || vstd[k]) poss = false;
	vstd.assign(MAX, false);
	dfs(k+1);
	if(vstd[k+2] || vstd[k+3]) poss = false;
	vstd.assign(MAX, false);
	dfs(k+3);
	if(vstd[k] || vstd[k+1]) poss = false;
	vstd.assign(MAX, false);
	dfs(k);
	if(vstd[k+3] || vstd[k+2]) poss = false;
	if(!poss){
		cout << "N" << endl;
	}else{
		cout << "S" << endl;
	}

	return 0;
}