#define pii pair<int, int>
vector<vector<pii>> g(N);
vector<bool> used(N);
vector<ll> d(N, LLINF);
priority_queue< pii, vector<pii>, greater<pii> > fila;

void dijkstra(int k){
    d[k] = 0;
    fila.push({0, k});

    while(!fila.empty()){
        auto [w, u] = fila.top();
        fila.pop();
        if (used[u]) continue;
        used[u] = true;

        for(auto [v, w]: g[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                fila.push({d[v], v});   
            }
        }
    }
}
