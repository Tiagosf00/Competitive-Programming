struct mint {
    int64_t r;
    constexpr mint(): r(0) {}
    constexpr mint(int64_t rr): r(rr) {if(r >= MOD || r <= -MOD) r %= MOD; if(r < 0) r += MOD;}
    mint inv() const {return fexp(r, MOD - 2);}
    mint operator - () const {return r ? MOD - r : 0;}
    mint operator * (const mint &t) const {return r * t.r % MOD;}
    mint operator / (const mint &t) const {return *this * t.inv();}
    mint operator += (const mint &t) {r += t.r; if(r >= MOD) r -= MOD; return *this;}
    mint operator -= (const mint &t) {r -= t.r; if(r < 0) r += MOD; return *this;}
    mint operator + (const mint &t) const {return mint(*this) += t;}
    mint operator - (const mint &t) const {return mint(*this) -= t;}
    mint operator *= (const mint &t) {return *this = *this * t;}
    mint operator /= (const mint &t) {return *this = *this / t;}
    bool operator == (const mint &t) const {return r == t.r;}
    bool operator != (const mint &t) const {return r != t.r;}
};

template<typename T>
struct poly {
    vector<T> a;

    void normalize() { // get rid of leading zeroes
        while(!a.empty() && a.back() == T(0)) {
            a.pop_back();
        }
    }
    
    poly(){}
    poly(T a0) : a{a0}{normalize();}
    poly(const vector<T> &t) : a(t){normalize();}
    
    poly operator -() const {
        auto t = *this;
        for(auto &it: t.a) {
            it = -it;
        }
        return t;
    }
    
    poly operator += (const poly &t) {
        a.resize(max(a.size(), t.a.size()));
        for(size_t i = 0; i < t.a.size(); i++) {
            a[i] += t.a[i];
        }
        normalize();
        return *this;
    }
    
    poly operator -= (const poly &t) {
        a.resize(max(a.size(), t.a.size()));
        for(size_t i = 0; i < t.a.size(); i++) {
            a[i] -= t.a[i];
        }
        normalize();
        return *this;
    }
    poly operator + (const poly &t) const {return poly(*this) += t;}
    poly operator - (const poly &t) const {return poly(*this) -= t;}

    pair<poly, poly> divmod_slow(const poly &b) const { // when divisor or quotient is small
        vector<T> A(a);
        vector<T> res;
        while(A.size() >= b.a.size()) {
            res.push_back(A.back() / b.a.back());
            if(res.back() != T(0)) {
                for(size_t i = 0; i < b.a.size(); i++) {
                    A[A.size() - i - 1] -= res.back() * b.a[b.a.size() - i - 1];
                }
            }
            A.pop_back();
        }
        std::reverse(begin(res), end(res));
        return {res, A};
    }
};
