struct DSU {
    int n;
    vi parent, size;

    DSU(int n) {
        this->n = n;
        parent.assign(n+1, 0);
        size.assign(n+1, 1);

        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    int find(int v) {
        if(v==parent[v])
            return v;
        return parent[v]=find(parent[v]);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if(a!=b) {
            if(size[a]<size[b])
                swap(a, b);

            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
