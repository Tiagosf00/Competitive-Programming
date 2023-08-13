// String Hash template
// constructor(s) - O(|s|)
// query(l, r) - returns the hash of the range [l,r] from left to right - O(1)
// query_inv(l, r) from right to left - O(1)

const ll MOD = 1e9+7;
const ll P = 31;
struct Hash {
    int n; string s;
    vector<ll> h, hi, p;
    Hash() {}
    Hash(string s): s(s), n(s.size()), h(n), hi(n), p(n) {
        for (int i=0;i<n;i++) p[i] = (P * (i ? p[i-1]:1)) % MOD;
        for (int i=0;i<n;i++) {
            h[i] = ((s[i] - 'a' + 1) * p[i] + (i ? h[i-1]:0)) % MOD;
            hi[i] = ((s[i] - 'a' + 1) * p[n-i-1] + (i ? hi[i-1]:0)) % MOD;
        }
    }
    int query(int l, int r) {
        ll hash = ((h[r] - (l ? h[l-1]:0)) * p[n-l-1] % MOD);
        return hash < 0 ? hash + MOD : hash;
    }
    int query_inv(int l, int r) {
        ll hash = ((hi[r] - (l ? hi[l-1]:0)) * p[r] % MOD);
        return hash < 0 ? hash + MOD : hash;
    }
};