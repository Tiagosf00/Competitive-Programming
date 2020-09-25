vector<int> d(n, INF);
deque<int> q;

void bfs(int x){
    d[x] = 0;
    q.push_front(x);
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(auto e: grafo[u]){
            int v = edge.ff;
            int w = edge.ss;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                if(w == 1)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
}
