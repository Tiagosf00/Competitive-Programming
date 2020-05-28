vi pi(const string &s){
    int n=s.size();
    vi p(n);
    for(int i=1, j=0; i<n; i++){
        while(j>0 and s[i]!=s[j]) j=p[j-1];
        if(s[j]==s[i]) j++;
        p[i]=j;
    }
    return p;
}

vi kmp(const string &t, const string &s){
    vi p = pi(s+'$'), match;
    int n=t.size(), m=s.size();
    for(int i=0, j=0; i<n; i++){
        while(j>0 and t[i]!=s[j]) j=p[j-1];
        if(t[i]==s[j]) j++;
        if(j==m) match.pb(i-j+1);
    }
    return match;
}
