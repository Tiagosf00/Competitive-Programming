struct Hash {
    vector<unordered_set<ll>> h;
    vector<ll> mods = {
        1000000009,1000000021,1000000033,1000000087,1000000093,1000000097,1000000103,
        1000000123,1000000181,1000000207,1000000223,1000000241,1000000271,1000000289,1000000297
    };
    ll p = 31;
    int num;

    Hash(int qt) {
        srand(time(0));
        num = qt;
        h.assign(num, unordered_set<ll>());
        random_shuffle(all(mods));
    }

    ll compute_hash(string const& s, ll p, ll m) {
        ll res = 0, p_pow = 1;

        for(char c : s) {
            res = ( res + (c-'a'+1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return res;
    }

    void add(string const& s) {
        forn(i, num) {
            ll value = compute_hash(s, p, mods[i]);
            h[i].insert(value);
        }
    }

    bool query(string const& s) {
        forn(i, num) {
            ll val = compute_hash(s, p, mods[i]);
            if(!h[i].count(val))
                return false;
        }
        return true;
    }
};
