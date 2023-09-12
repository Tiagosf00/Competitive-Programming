// Longest Common Subsequence
string lcs(string x, string y) {
    int n = x.size(), m = y.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (i == 0 or j == 0) continue;
            if (x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // int len = dp[n][m];
    string ans = "";
    int i = n-1, j = m-1;
    while (i >= 0 and j >= 0) { // recover string
        if (x[i] == y[j]) ans.pb(x[i]), i--, j--;
        else if (dp[i][j+1] > dp[i+1][j]) i--;
        else j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}