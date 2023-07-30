int logv[N+1];
void make_log() {
    logv[1] = 0; // pre-computar tabela de log
    for (int i = 2; i <= N; i++)
        logv[i] = logv[i/2] + 1;
}
struct Sparse {
    int n;
    vector<vector<int>> st;

    Sparse(vector<int>& v) {
        n = v.size();
        int k = logv[n];
        st.assign(n+1, vector<int>(k+1, 0));

        for (int i=0;i<n;i++) {
            st[i][0] = v[i];
        }

        for(int j = 1; j <= k; j++) {
            for(int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = f(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    int f(int a, int b) {
        return min(a, b);
    }

    int query(int l, int r) {
        int k = logv[r-l+1];
        return f(st[l][k], st[r - (1 << k) + 1][k]);
    }
};


struct Sparse2d {
    int n, m;
    vector<vector<vector<int>>> st;
 
    Sparse2d(vector<vector<int>> mat) {
        n = mat.size();
        m = mat[0].size();
        int k = logv[min(n, m)];
 
        st.assign(n+1, vector<vector<int>>(m+1, vector<int>(k+1)));
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                st[i][j][0] = mat[i][j];
 
        for(int j = 1; j <= k; j++) {
            for(int x1 = 0; x1 < n; x1++) {
                for(int y1 = 0; y1 < m; y1++) {
                    int delta = (1 << (j-1));
                    if(x1+delta >= n or y1+delta >= m) continue;
 
                    st[x1][y1][j] = st[x1][y1][j-1];
                    st[x1][y1][j] = f(st[x1][y1][j], st[x1+delta][y1][j-1]);
                    st[x1][y1][j] = f(st[x1][y1][j], st[x1][y1+delta][j-1]);
                    st[x1][y1][j] = f(st[x1][y1][j], st[x1+delta][y1+delta][j-1]);
                }
            }
        }
    }
 
    // so funciona para quadrados
    int query(int x1, int y1, int x2, int y2) {
        assert(x2-x1+1 == y2-y1+1);
        int k = logv[x2-x1+1];
        int delta = (1 << k);
 
        int res = st[x1][y1][k];
        res = f(res, st[x2 - delta+1][y1][k]);
        res = f(res, st[x1][y2 - delta+1][k]);
        res = f(res, st[x2 - delta+1][y2 - delta+1][k]);
        return res;
    }
 
    int f(int a, int b) {
        return a | b;
    }
 
};
