// Solves https://codeforces.com/contest/1279/problem/F

// dado um vetor de inteiros, escolha k subsegmentos disjuntos de soma máxima
// em vez de rodar a dp[i][k] = melhor soma até i usando k segmentos,
// vc roda uma dp[i] adicionando um custo W toda vez que usa um novo subsegmento,
// e faz busca binária nesse W pra achar o custo mínimo que usa exatamente K intervalos

ll n, k, L;
pll check(ll w, vl& v){
    vector<pll> dp(n+1);
    dp[0] = {0,0};
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        dp[i].ff += v[i];
        if(i-L>=0){
            pll t = {dp[i-L].ff + w, dp[i-L].ss + 1};
            dp[i] = min(dp[i], t);
        }
    }

    return dp[n];
}

ll solve(vl v){
    ll l=-1, r=n+1, ans=-1;
    while(l<=r){
        ll mid = (l+r)/2;
        pll c = check(mid, v);
        if(c.ss <= k){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }

    pll c = check(ans, v);

    if(ans < 0) return 0;

    // we can simply use k insted of c.ss ~magic~
    return c.ff - ans*k;
}

int32_t main()
{sws;

    string s;
    cin >> n >> k >> L;
    cin >> s;

    vl upper(n+1, 0), lower(n+1, 0);
    for(int i=0;i<n;i++)
        if('A'<= s[i] and s[i] <= 'Z')
            upper[i+1] = 1;
    for(int i=0;i<n;i++)
        if('a'<= s[i] and s[i] <= 'z')
            lower[i+1] = 1;

    cout << min(solve(lower),
                solve(upper)) << endl;

    return 0;
}