vector<vi> grafo(MAX, vi());
int grau[MAX]; // Quantas arestas chegam no indice i

vi topological_sort(int n){
    vi resp;
    for(int i=1;i<=n;i++)
        if(!grau[i])
            resp.push_back(i);
 
    int k=0;
    while(k < (int)resp.size()){
        int u = resp[k];
        k++;
        for(auto v: grafo[u]){
            grau[v]--;
            if(!grau[v])
                resp.pb(v);
        }
    }

    if((int)resp.size() < n)
        cout << "impossivel\n";

    return resp;
}