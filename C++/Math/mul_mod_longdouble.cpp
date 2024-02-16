ll mulmod(ll a, ll b, ll mod) {
    ll q = ll((long double)a * (long double)b / (long double)mod);
    ll r = (a * b - mod * q) % mod;
    if(r < 0) r += mod;
    return r;
}
