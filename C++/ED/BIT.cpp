struct FT {
    vi bit;  // indexado em 1
    int n;

    FT(int n) {
        this->n = n+1;
        bit.assign(n+1, 0);
    }

    int sum(int idx) {
        int ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) { // [l, r]
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};