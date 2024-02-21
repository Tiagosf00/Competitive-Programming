// retorna o numero de solucoes, com 2 representando infinitas solucoes (no caso real)
// testado em kattis::equationsolver, com n = 100, EPS = 1e-12 e erro do problema sendo 1e-3
const ld EPS = 1e-12;
bool zero(ld a) {
    return abs(a) < EPS;
}

bool best(ld a, ld b) {
    if(zero(a)) return 0;
    if(zero(b)) return 1;
    return abs(a) < abs(b);
}

template<typename T>
pair<int, vector<T>> gauss(vector<vector<T>> a, vector<T> b) {
    int n = a.size(), m = a[0].size();
    for(int i = 0; i < n; i++) a[i].pb(b[i]);

    int rank = 0;
    vector<int> col(n); 
    for(int r = 0, c = 0; r < n and c < m; c++, r++) {
        for(int i = r+1; i < n; i++) {
            if(best(a[i][c], a[r][c])) swap(a[i], a[r]);
        }

        if(zero(a[r][c])) {
            r--;
            continue;
        }
        col[r] = c;
        rank++;

        T inv = 1/a[r][c]; // tem que ser assim pro mod nao ficar n^3 log
        for(int i = 0; i < n; i++) {
            if(i == r) continue;
            if(zero(a[i][c])) continue;

            T mul = -a[i][c]*inv;
            for(int j = c; j <= m; j++) {
                a[i][j] = mul*a[r][j] + a[i][j];
            }
        }
    }

    vector<T> res(n, 0);
    for(int i = 0; i < rank; i++) res[col[i]] = a[i][m]/a[i][col[i]];
    for(int i = rank; i < n; i++) if(!zero(a[i][m])) return {0, {}};

    return {(rank == n ? 1 : 2), res};
}
