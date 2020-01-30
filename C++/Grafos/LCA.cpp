const int K = 100;
int logv[MAX+1];
int st[MAX][K];
vector<vi> grafo(200010, vi());

void make(){
    logv[1] = 0; // pre-computar tabela de log
    for (int i = 2; i <= MAX; i++)
        logv[i] = logv[i/2] + 1;
}

void precompute(int N, int array[]) { //
  for (int i = 0; i < N; i++)
      st[i][0] = array[i];

  int k = logv[N];
  for (int j = 1; j <= k; j++)
      for (int i = 0; i + (1 << j) <= N; i++)
          st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) {
    int j = logv[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);

    return minimum;
}

int start[MAX+1], dfs_time;
int tour[2*MAX+1], id[2*MAX+1];

void dfs(int u, int pai=-1){
    start[u] = dfs_time;
    id[dfs_time] = u;
    tour[dfs_time++] = start[u];
    for(int v : grafo[u]){
        if(v==pai)
            continue;
        dfs(v, u);
        id[dfs_time] = u;
        tour[dfs_time++] = start[u];
    }
}

int LCA(int u, int v)
{
    if(start[u] > start[v])
        swap(u, v);
    return id[query(start[u], start[v])];
}

int main()
{
    int N, k, a, b;
    cin >> N;

    for(int i=0;i<N-1;i++)
    {
        cin >> a >> b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }
    dfs(1);

    make();
    precompute(2*N, tour);


    cin >> k;
    for(int i=0;i<k;i++)
    {
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }

    return 0;
}
