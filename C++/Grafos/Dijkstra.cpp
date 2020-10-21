// Dijkstra - Shortest Path

vector<vii> grafo(MAX+1, vii());
vi d(MAX+1, INF);
priority_queue< pii, vii, greater<pii> > fila;

void dijkstra(int k){
    d[k]=0;
    fila.push({0, k});

    while(!fila.empty()){
        int w=fila.top().ff, u=fila.top().ss;
        fila.pop();
        if(w>d[u]) continue;

        for(auto [v, w]: grafo[u]){
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                fila.push({d[v], v});   
            }
        }
    }
}
