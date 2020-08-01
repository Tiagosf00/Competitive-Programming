int w, n;
int c[MAX], v[MAX];

int unbounded_knapsack(){
    int dp[w+1];
    memset(dp, 0, sizeof dp);

    for(int i=0;i<=w;i++)
        for(int j=0;j<n;j++)
            if(c[j] <= i)
                dp[i] = max(dp[i], dp[i-c[j]] + v[j]);

    return dp[w];
}
