vector<int> g[N];
vector<int> ans;

void dfs(int u) {
  while(!g[u].empty()) {
    int v = g[u].back();
    g[u].pop_back();
    dfs(v);
  }
  ans.push_back(u);
}
