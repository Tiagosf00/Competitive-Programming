// KOSARAJU - O(V+E) - encontra componentes fortemente conexos
// g -> grafo, gt -> grafo tempo
// vis -> visitado, cor -> componente fortemente conexo ordenado topologicamente
vector<int> g[N], gt[N], S; int vis[N], cor[N];
void dfs(int u){
	vis[u] = 1; for(int v : g[u]) if(!vis[v]) dfs(v);
	S.push_back(u);
}
void dfst(int u, int e){
	cor[u] = e;
	for(int v : gt[u]) if(!cor[v]) dfst(v, e);
}
void kosaraju(){
	for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
    for(int i = 1; i <= n; i++) for(int j : g[i])
        gt[j].push_back(i);
	int e = 0; reverse(S.begin(), S.end());
	for(int u : S) if(!cor[u]) dfst(u, ++e);
}
