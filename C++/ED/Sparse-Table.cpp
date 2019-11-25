// Precompute log2
int logv[MAXN+1];
logv[1] = 0;
for (int i = 2; i <= MAXN; i++)
    logv[i] = logv[i/2] + 1;
 
int st[MAXN][K];
 
void precompute(int N)
{
    for (int i = 0; i < N; i++)
        st[i][0] = array[i];
 
    int k = logv[N];
    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}
 
int query(int L, int R)
{
    int j = logv[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
}