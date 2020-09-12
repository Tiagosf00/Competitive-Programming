int sz[MAX];
bool erased[MAX];
vi grafo[MAX];

void dfs(int u, int p=-1){
    sz[u] = 1;
    for(int v: grafo[u]) if(v!=p and !erased[v]){
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int p=-1, int size=-1){
    if(size==-1) size = sz[u];
    for(int v: grafo[u])
        if(v!=p and !erased[v] and sz[v]>size/2)
            return centroid(v, u, size);
    return u;
}

pii centroids(int u=1){ // idx 1
    dfs(u);
    int c1=centroid(u), c2=c1;
    for(int v: grafo[c1]) if(2*sz[v]==sz[u]) c2=v;
    return {c1, c2};
}