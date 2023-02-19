vector<vector<int>> g(N);
int grau[N];

vector<int> topological_sort(int n){
    vector<int> resp;
    for(int i=1;i<=n;i++)
        if(!grau[i])
            resp.push_back(i);
 
    int k=0;
    while(k < (int)resp.size()){
        int u = resp[k];
        k++;
        for(auto v: g[u]){
            grau[v]--;
            if(!grau[v])
                resp.pb(v);
        }
    }

    if((int)resp.size() < n)
        cout << "impossivel\n";

    return resp;
}