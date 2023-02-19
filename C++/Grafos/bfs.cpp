vector<vector<int>> g(N);
queue<int> q;
vector<bool> used(N);
vector<int> d(N), path(N);

void bfs(int x){
    q.push(x);
    used[x] = true;
    path[x] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: g[u]) {
            if(!used[v]){
                used[v] = true;
                q.push(v);
                d[v] = d[u] + 1;
                path[v] = u;
            }
        }
    }
}