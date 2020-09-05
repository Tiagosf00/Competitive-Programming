#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define vi vector<int>
#define ii pair<int, int>
#define ll long long int
#define MAX 200010
#define MOD 1000000007
#define oo 0x7fffffff
#define endl '\n'
using namespace std;

int N;
vector<vector<int>> G(110);
vector<bool> visited;

struct SPAM{
	int src, t1, t2;
	vector<string> a;
};

void dfs(int u){
	if(visited[u])
		return;
	visited[u] = true;
	for(auto v : G[u]){
		dfs(v);
	}
}

string classify(SPAM sp, int sent){
	if(sent < sp.t1) return sp.a[0];
	if(sent >= sp.t1 && sent < sp.t2) return sp.a[1];
	return sp.a[2];
}

void solve(vector<string>&nms, vector<SPAM>&sps){
	int mtx[N][sps.size()];
	REP(i, 0, sps.size()){
		visited.assign(110, false);
		dfs(sps[i].src);
		REP(j, 0, N){
			int sent = 0;
			if(visited[j]){
				for(auto v : G[j])
					if(visited[v]) sent++;
			}
			mtx[j][i] = sent;
		}
	}
	REP(i, 0, N){
		cout << nms[i] << ": ";
		REP(j, 0, sps.size()){
			cout << classify(sps[j], mtx[i][j]) << " ";
		}
		cout << endl;
	}
}

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	while(cin >> N && N){
		REP(i, 0, N){
			int v;
			while(cin >> v && v){
				G[i].pb(v-1);
			}
		}
		vector<SPAM> sps;
		int src;
		while(cin >> src && src){
			SPAM x;
			x.src = src-1;
			cin >> x.t1 >> x.t2;
			REP(i, 0, 3){
				string s;
				cin >> s;
				x.a.pb(s);
			}
			sps.pb(x);
		}

		vector<string> nms(N);
		REP(i, 0, N){
			cin >> nms[i];
		}

		solve(nms, sps);
		REP(i, 0, N) G[i].resize(0);
	}

    return 0;
}