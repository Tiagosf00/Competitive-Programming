//DFS (Depth First Search) O(V+A)

void DFS(int x){
    for(int i=0; i<(int)vizinhos[x].size(); i++){
        int v = vizinhos[x][i];
        if(componente[v] == -1){
            componente[v] = componente[x];
            DFS(v);
        }
    }
}