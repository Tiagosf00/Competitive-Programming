logv[1] = 0; // pre-computar tabela de log
for (int i = 2; i <= MAXN; i++)
    logv[i] = logv[i/2] + 1;

int logv[MAXN+1];
int st[MAXN][K];

// operacao da sparse table deve ser idempotente -> op(x, x) = x
void precompute(int N) { // 
  for (int i = 0; i < N; i++)
      st[i][0] = array[i];

  int k = logv[N];
  for (int j = 1; j <= k; j++)
      for (int i = 0; i + (1 << j) <= N; i++)
          st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) {
    int j = logv[R - L + 1];
    int maximum = max(st[L][j], st[R - (1 << j) + 1][j]);
    
    return maximum;
}
