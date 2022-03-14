// Subsequence with the biggest sum%m value O(2^(n/2)*n)

int n, m, a[40];

void comb(int l, int r, vi &v){
    int sz = r-l+1;
    for(int i=0;i<(1<<sz);i++){
        int sum = 0;
        for(int j=0;j<sz;j++)
            if(i & (1<<j))
                sum = (sum + a[l+j])%m;
        v.pb(sum);
    }

    sort(v.begin(), v.end());
}

int merge(vi &x, vi &y){
    int k=y.size()-1, ans=0;
    for(auto v: x){
        while(k>0 and v+y[k]>=m)
            k--;
        ans = max(ans, v+y[k]);
    }
    return ans;
}


int main()
{sws;

    vi x, y;
    cin >> n >> m;

    for(int i=0;i<n;i++)
        cin >> a[i];

    comb(0, n/2, x);
    comb(n/2 + 1, n-1, y);
    cout << merge(x, y) << endl;

    return 0;
}