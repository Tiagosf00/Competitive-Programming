for (int i=1;i<=n;i++) {
    opt[i][i] = i;
    dp[i][i] = ?; // initialize
}
auto cost = [&](int l, int r) {
    return ?;
};

for (int l=n-1;l>=1;l--) {
    for (int r=l+1;r<=n;r++) {
        ll ans = LLINF;
        for (int k=opt[l][r-1]; k<=min(r-1, opt[l+1][r]); k++) {
            ll best = dp[l][k] + dp[k+1][r];
            if (ans > best) {
                ans = best;
                opt[l][r] = k;
            }
        }
        dp[l][r] = ans + cost(l, r);
    }
}

cout << dp[1][n] << endl;