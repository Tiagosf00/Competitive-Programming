ll cost(int l, int r) {
    return ?;
}
 
void process(int l, int r, int optl, int optr) {
    if (l > r) return;
    int opt = optl;
    int mid = (l + r) / 2;
    for (int i=optl;i<=min(mid-1, optr);i++) {
        if (dp[i] + cost(i+1, mid) < dp2[mid]) {
            opt = i;
            dp2[mid] = dp[i] + cost(i+1, mid);
        }
    }
    process(l, mid-1, optl, opt);
    process(mid+1, r, opt, optr);
}

int main() {
    for (int i=0;i<n;i++) {
        dp[i] = cost(0, i);
        dp2[i] = LLINF;
    }
 
    for (int i=0;i<k-1;i++) {
        process(0, n-1, 0, n-1);
        swap(dp, dp2);
        dp2.assign(N, LLINF);
    }
}