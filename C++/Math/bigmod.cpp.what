ll mod(string a, ll p) {
    ll res = 0, b = 1;
    reverse(all(a));
    
    for(auto c : a) {
        ll tmp = (((ll)c-'0')*b) % p;
        res = (res + tmp) % p;

        b = (b * 10) % p;
    }

    return res;
}
