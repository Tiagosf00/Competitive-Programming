struct Gauss {
    array<ll, LOG_MAX> vet;
    int size;
    Gauss() : size(0) {
        fill(vet.begin(), vet.end(), 0);
    }
    Gauss(vector<ll> vals) : size(0) {
        fill(vet.begin(), vet.end(), 0);
        for(ll val : vals) add(val);
    }
    bool add(ll val) {
        for(int i = LOG_MAX-1; i >= 0; i--) if(val & (1LL << i)) {
            if(vet[i] == 0) {
                vet[i] = val;
                size++;
                return true;
            }
            val ^= vet[i];
        }
        return false;
    }
};
