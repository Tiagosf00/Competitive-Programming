// Bitwise 
    #pragma GCC target("popcnt")
    unsigned char a = 5, b = 9; // a = (00000101), b = (00001001)

    AND -          a&b   // The result is 00000001 (1)
    OR -           a|b   // The result is 00001101 (13)
    XOR -          a^b   // The result is 00001100 (12)
    NOT -          ~a    // The result is 11111010 (250)
    Left shift -   b<<1  // The result is 00010010 (18)
    Right shift -  b>>1  // The result is 00000100 (4)

    // Exchange two int variables

	    a^=b;
	    b^=a;
	    a^=b;

    // Even or Odd

        (x & 1)? printf("Odd"): printf("Even");

    // Turn on the j-th bit

        int S = 34; //(100010)
        int j = 3;

        S = S | (1<<j);

    // Turn off the j-th bit

        int S = 42; //(101010)
        int j = 1;

        S &= ~(1<<j)

        S == 40 //(101000)

    // Check the j-th element

        int S = 42; //(101010)
        int j = 3;

        T = S & (1<<j); // T = 0

    // Least significant bit (lsb)

        int lsb(int x){ return x&-x; }

    // Exchange o j-th element

        S ^= (1<<j)

    // Position of the first bit on

        T = (S & (-S))
        T -> 4 bit ligado //(1000)

    // Most significant digit of N

        double K = log10(N);
        K = K - floor(K);
        int X = pow(10, K);

    // Number of digits in N

        X =floor(log10(N)) + 1; 

    // Power of two

        bool isPowerOfTwo(int x){ return x && (!(x&(x-1))); }

    // Turn off the first bit 1
        m = m & (m-1);

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

        int flog2(int x){ return 32-1-__builtin_clz(x); }

        int flog2ll(ll x){ return 64-1-__builtin_clzll(x); }

    // iterate all submasks of a mask
        
        for (int m=mask;m>=0;m=(m-1)&mask)