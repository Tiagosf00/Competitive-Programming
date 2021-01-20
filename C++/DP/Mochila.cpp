int val[MAXN], peso[MAXN], dp[MAXN][MAXS];

int knapsack(int n, int m){ // n Objetos | Peso max
    for(int i=0;i<=n;i++){
       for(int j=0;j<=m;j++){
            if(i==0 or j==0)
                dp[i][j] = 0;
            else if(peso[i-1]<=j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-peso[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
       }
    }
    return dp[n][m];
}


// space optimized

int val[MAX], wt[MAX], dp[MAX];
int knapsack(int n, int W){
    for(int i=0; i < n; i++)
        for(int j=W; j>=wt[i]; j--) 
            dp[j] = max(dp[j], val[i] + dp[j-wt[i]]); 
    return dp[W];
} 