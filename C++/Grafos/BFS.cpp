//BFS (Breadth First Search) O(V+A)

vector<vector<int>> adj;  // adjacency list representation
int n; // number of nodes
int s; // source vertex

queue<int> q;
vector<int> d(n, INF);
d[s]=0;

q.push(s);
used[s] = true;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (d[u] > d[v] + 1) {
            q.push(u);
            d[u] = d[v] + 1;
        }
    }
}