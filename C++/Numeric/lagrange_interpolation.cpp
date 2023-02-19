// Lagrange's interpolation O(n^2)
ld interpolate(vector<pair<int, int>> d, ld x){
    ld y = 0;
    int n = d.size();
    for(int i=0;i<n;i++){
        ld yi = d[i].ss;
        for(int j=0;j<n;j++)
            if(j!=i)
               yi = yi*(x - d[j].ff)/(ld)(d[i].ff - d[j].ff);

        y += yi;
    }
    return y;
}

// O(n)

template<typename T = mint>
struct Lagrange {
    vector<T> y, den, l, r;
    int n;
    Lagrange(const vector<T>& _y) : y(_y), n(_y.size()) {
        den.resize(n, 0);
        l.resize(n, 0); r.resize(n, 0);

        for (int i = 0; i < n; i++) {
            den[i] = ifac[i] * ifac[n - 1 - i];
            if ((n - 1 - i) % 2 == 1) den[i] = -den[i];
        }
    }

    T eval(T x) {
        l[0] = 1;
        for (int i = 1; i < n; i++)
            l[i] = l[i-1] * (x + -T(i-1));

        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            r[i] = r[i+1] * (x + -T(i+1));

        T ans = 0;
        for (int i = 0; i < n; i++) {
            T num = l[i] * r[i];
            ans = ans + y[i] * num * den[i];
        }
        return ans;
    }
};