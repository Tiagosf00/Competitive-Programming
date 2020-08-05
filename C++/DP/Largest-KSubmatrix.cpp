int n, m;
int a[MAX][MAX];
// Largest K such that exists a block K*K with equal numbers
int largestKSubmatrix(){ 
    int dp[n][m];
    memset(dp, 0, sizeof(dp));

    int result = 0; 
    for(int i = 0 ; i < n ; i++){ 
        for(int j = 0 ; j < m ; j++){
            if(!i or !j) 
                dp[i][j] = 1; 
            else if(a[i][j] == a[i-1][j] and 
                    a[i][j] == a[i][j-1] and 
                    a[i][j] == a[i-1][j-1])
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),
                               dp[i-1][j-1]) + 1;
            else dp[i][j] = 1;

            result = max(result, dp[i][j]);
        }
    }

    return result;
}