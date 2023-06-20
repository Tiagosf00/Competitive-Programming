// Least significant bit (lsb)
    int lsb(int x){ return x&-x; }

// Power of two
    bool isPowerOfTwo(int x){ return x && (!(x&(x-1))); }

// Built-in functions

    // Number of bits 1
    __builtin_popcount()
    __builtin_popcountll()

    // Number of leading zeros
    __builtin_clz()
    __builtin_clzll()

    // Number of trailing zeros
    __builtin_ctz()
    __builtin_ctzll()

    // floor(log2(x))
    int flog2(int x)  { return 32-1-__builtin_clz(x); }
    int flog2ll(ll x) { return 64-1-__builtin_clzll(x); }
