ll fexp(ll b, ll e) {
    ll ans = 1;
    b %= MOD;
    while (e) {
        if (e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e /= 2;
    }
    return ans;
}