void DFS(int u, int pai){
    for(auto v: grafo[u]) if(v!=pai){
        DFS(v, u);
    }
}