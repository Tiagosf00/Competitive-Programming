ll fexp(ll b, ll e) {
    b %= MOD;
    ll ans = 1;
    while (e) {
        if (e & 1) (ans *= b) %= MOD;
        e >>= 1;
        (b *= b) %= MOD;
    }
    return ans;
}