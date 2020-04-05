vector<vi> grafo(MAX, vi());
int grau[MAX]; // Quantas arestas chegam no indice i

vi topological_sort(int N)
{
	vi resp;
    for(int i=0;i<N;i++)
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
    return resp;
}