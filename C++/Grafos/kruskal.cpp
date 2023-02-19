// Uses DSU .join() and .find()
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

DSU dsu(N);
vector<Edge> edges, result;
int cost = 0;

sort(edges.begin(), edges.end());

for(auto e : edges) {
    if (dsu.find(e.u) != dsu.find(e.v)) {
        cost += e.weight;
        result.push_back(e); // vector com as arestas da MST
        dsu.join(e.u, e.v);
    }
}
