// Dijkstra - Shortest Path

vector<vii> grafo(N+1, vii());
vi d(N+1, INF);
priority_queue< pii, vii, greater<pii> > fila;

void dijkstra(int k){
    d[k]=0;

    fila.push(mp(k, 0));

    while(!fila.empty()){
        int u=fila.top().ff, w=fila.top().ss;
        fila.pop();
        if(w>d[u]) continue;

        for(auto [v, w]: grafo[u]){
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                fila.push(mp(v, d[v]));   
            }
        }
    }
}
