struct frac {
    ll num, den;
    frac(ll num=0, ll den=1) : num(num), den(den) {}
    frac operator+(const frac &o) const { return {num*o.den + o.num*den, den*o.den}; }
    frac operator-(const frac &o) const { return {num*o.den - o.num*den, den*o.den}; }
    frac operator*(const frac &o) const { return {num*o.num, den*o.den}; }
    frac operator/(const frac &o) const { return {num*o.den, den*o.num}; }
    bool operator<(const frac &o) const { return num*o.den < den*o.num; }
};
