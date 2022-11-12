ll fact[N], ifact[N];
void build_fact() {
    fact[0] = 1;
    for (int i=1;i<N;i++)
        fact[i] = (fact[i-1] * i) % MOD;
    ifact[N-1] = fexp(fact[N-1], MOD-2);
    for (int i=N-2;i>=0;i--)
        ifact[i] = (ifact[i+1] * (i+1)) % MOD;
}
ll c(ll n, ll k) {
    return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}