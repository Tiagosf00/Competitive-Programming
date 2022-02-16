vector<vii> g(MAX, vii());
vi d(MAX, INF);
priority_queue< pii, vii, greater<pii> > fila;

void dijkstra(int k){
    d[k] = 0;
    fila.push({0, k});

    while(!fila.empty()){
        auto [w, u] = fila.top();
        fila.pop();
        if(w > d[u]) continue;

        for(auto [v, w]: g[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                fila.push({d[v], v});   
            }
        }
    }
}
