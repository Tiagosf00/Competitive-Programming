struct mint {
    int x;
    mint(int _x = 0) : x(_x) { }
    mint operator +(const mint &o) const { return x + o.x >= MOD ? x + o.x - MOD : x + o.x; }
    mint operator *(const mint &o) const { return mint((ll)x * o.x % MOD); }
    mint operator -(const mint &o) const { return *this + (MOD - o.x); }
    mint inv() { return pwr(MOD - 2); }
    mint pwr(ll e) {
        mint ans = 1;
        for (mint b=x; e; e >>= 1, b = b * b)
            if (e & 1) ans = ans * b;
        return ans;
    }
};

mint fac[N], ifac[N];
void build_fac() {
    fac[0] = 1;
    for (int i=1;i<N;i++)
        fac[i] = fac[i-1] * i;
    ifac[N-1] = fac[N-1].inv();
    for (int i=N-2;i>=0;i--)
        ifac[i] = ifac[i+1] * (i+1);
}
mint c(ll n, ll k) {
    if (k > n) return 0;
    return fac[n] * ifac[k] * ifac[n-k];
}
