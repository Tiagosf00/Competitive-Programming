ll compute_hash(string const& s) {
    const ll p = 31; // primo, melhor = perto da quantidade de caracteres
    const ll m = 1e9 + 9; // maior mod = menor probabilidade de colisao
    ll hash_value = 0;
    ll p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

