// Modular exponentiaion - (x^y)%mod in O(log y)
ll power(ll x, ll y, ll mod){
    ll res = 1;
    x%=mod;
    while(y){ 
        if(y&1)
            res=(res*x)%mod;
        y=y>>1;
        x=(x*x)%mod;
    }
    return res;
}
