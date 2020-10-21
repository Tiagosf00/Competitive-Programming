vi z_algo(const string &s)
{   // returns vector for each idx where a prefix of size i starts.
    int n = s.size();
    int L = 0, R = 0;
    vi z(n, 0);
    for(int i = 1; i < n; i++){
        if(i <= R)
            z[i] = min(z[i-L], R - i + 1);
        while(z[i]+i < n and s[ z[i]+i ] == s[ z[i] ])
            z[i]++;
        if(i+z[i]-1 > R){
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}