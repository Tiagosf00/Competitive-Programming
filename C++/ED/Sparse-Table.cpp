int logv[MAX+1];
void make_log() {
    logv[1] = 0; // pre-computar tabela de log
    for (int i = 2; i <= MAX; i++)
        logv[i] = logv[i/2] + 1;
}

struct Sparse {
    int n, k;
    vector<vector<int>> st;

    Sparse(int n, vi array) {
        this->n = n;
        st.assign(n+1, vector<int>(k+1, 0));

        for (int i = 0; i < n; i++)
            st[i][0] = array[i];

        int k = logv[n];
        for (int j = 1; j <= k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = f(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    }

    int f(int a, int b) {
        return max(a, b);
    }

    int query(int L, int R) {
        int j = logv[R - L + 1];
        int res = f(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};
