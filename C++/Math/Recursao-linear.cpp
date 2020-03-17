vector<vl> id(int n) {
    vector<vl> res(n, vl(n, 0));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    return res;
}

vector<vl> mult(vector<vl> a, vector<vl> b, int n) {
    vector<vl> res(n, vl(n, 0));

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            ll val = 0;
            for(int k = 0; k < n; k++) {
                ll delta = (a[row][k] * b[k][col]) % MOD;
                val = (val + delta) % MOD;
            }
            res[row][col] = val;
        }
    }

    return res;
}

vector<vl> fexp(vector<vl> b, ll e, int n) {
    if(e == 0) {
        return id(n);
    }

    vector<vl> res = fexp(b, e/2, n);
    res = mult(res, res, n);

    if(e%2)
        res = mult(res, b, n);

    return res;
}

// k = tamanho da recorrencia/matriz, n = n-esimo termo
// f(n) = c1*f(n-1) + c2*f(n-2) + ... + ck*f(n-k)
// base -> [f(k-1), f(k-2), ..., f(0)]
// coeficientes -> [c1, c2, ..., ck]
vl solve(int k, int n, vl base, vl coef) {
    vector<vl> inicial;
    inicial.pb(coef);
    for(int row = 0; row < k-1; row++) {
        vl tmp;
        for(int col = 0; col < k; col++) {
            if(col == row)
                tmp.pb(1);
            else
                tmp.pb(0);
        }
        inicial.pb(tmp);
    }

    vector<vl> matexp = fexp(inicial, max(0, n-k+1), k);
    vl res(k);

    for(int row = 0; row < k; row++) {
        ll val = 0;
        for(int aux = 0; aux < k; aux++) {
            val += matexp[row][aux]*base[aux];
        }
        res[row] = val; // res = (f(n), f(n-1), ..., f(n-k+1))
    }

    return res;
}
