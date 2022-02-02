ll fexp(ll b, ll e, ll mod) {
    ll res = 1;
    b %= mod;
    while(e){ 
        if(e & 1LL)
            res = (res * b) % mod;
        e = e >> 1LL;
        b = (b * b) % mod;
    }
    return res;
}
