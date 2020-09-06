vi g[MAX];
int in[MAX], cor[MAX];
void kahn(int n) {
    int label = 1;
    priority_queue<int, vector<int>, greater<int>> pq; // trocar por queue para O(n)
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {
            pq.push(i);
        }
    }

    while(pq.size()) {
        int u = pq.top(); pq.pop();
        cor[u] = label++;
        for(auto prox : g[u]) {
            in[prox]--;
            if(in[prox] == 0) {
                pq.push(prox);
            }
        }
    }
}
