#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define oo INT_MAX
vector<pair<int, int>> magia(MAX);
vector<int> monsters_life;
int dp[MAX][MAX];
class salao{
public:
	int v, w;
	bool operator<(const salao& lhc) const{
		return this->w < lhc.w;
	}
};
int dijkstra(vector<vector<salao>>& cave, int V, int src){
	int dist[V+1];
	priority_queue<salao> min_weight;
	for(int v=0;v<=V;v++){
		salao u;
		dist[v] = INT_MAX;
		u.v = v; u.w = dist[v];
		if(v == src){ u.w = 0; dist[v] = 0; }
		min_weight.push(u);
	}
	while(!min_weight.empty()){
		int u = (min_weight.top()).v;
		min_weight.pop();
		for(int i=0;i<(int)cave[u].size();i++){
			int v = cave[u][i].v;
			int add = cave[u][i].w;
			if(dist[u] != INT_MAX && add + dist[u] < dist[v]){
				dist[v] = dist[u] + add;
				salao upd; upd.v = v; upd.w = dist[v];
				min_weight.push(upd);
			}
		}
	}
	return dist[V] == INT_MAX ? -1 : dist[V];
}

void knapsack(int n){
	int W = MAX;
	for(int i=0;i<=W;i++){
		dp[0][i] = oo;
	}

	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int j=0;j<=W;j++){
			dp[i][j] = dp[i-1][j];
			if(j <= magia[i-1].second){
				dp[i][j] = min(dp[i][j], magia[i-1].first);
			}else{
				dp[i][j] = min(dp[i][j], dp[i][j-magia[i-1].second] + magia[i-1].first);
			}
		}
	}
}

int main(){
	int M, N, G, K;
	while(scanf("%d%d%d%d", &M, &N, &G, &K)){
		if(M == 0 && N == 0 && G == 0 && K == 0){
			break;
		}
		monsters_life.assign(N+1, 0);
		vector<vector<salao>> Caverna(MAX);
		for(int i=0;i<M;i++){
			int mana, dano;
			scanf("%d%d", &mana, &dano);
			magia[i] = make_pair(mana, dano);
		}
		for(int i=0;i<G;i++){
			int A, B;
			scanf("%d%d", &A, &B);
			Caverna[A].push_back({B, 0});
			Caverna[B].push_back({A, 0});
		}
		knapsack(M);
		for(int i=0;i<K;i++){
			int S, ML;
			scanf("%d%d", &S, &ML);
			monsters_life[S] += dp[M][ML];
		}
		for(int u=1;u<=N;u++){
			if(monsters_life[u] > 0){
				for(int i=0;i<(int)Caverna[u].size();i++){
					Caverna[u][i].w += monsters_life[u];
				}
			}
		}

		int min_path = dijkstra(Caverna, N, 1);
		cout << (min_path == -1 ? -1 : 
			     min_path + monsters_life[N]) << endl;
	}
	return 0;
}