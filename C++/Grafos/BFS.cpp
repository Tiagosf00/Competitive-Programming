queue<int> q;
vector<bool> used(n);
vi d(n), p(n);

void bfs(int x){
    q.push(x);
    used[x] = true;
    p[x] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]) {
            if(!used[v]){
                used[v] = true;
                q.push(v);
                d[v] = d[u] + 1;
                p[v] = u;
            }
        }
    }
}

// Restore
if(!used[u])
    cout << "No path!";
else{
    vi path;
    for(int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}