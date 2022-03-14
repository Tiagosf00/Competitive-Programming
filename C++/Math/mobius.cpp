vi mobius(int n) {
    // g(n) = sum{f(d)} => f(n) = sum{mu(d)*g(n/d)}
    vi mu(n+1);
    mu[1] = 1; mu[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + i; j <= n; j += i)
            mu[j] -= mu[i];

    return mu;
}
