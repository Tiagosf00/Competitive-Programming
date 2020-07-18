vi suffix_array(string s){
    s.pb('$');
    int n = s.size();

    vi p(n), c(n);
    vector< pair<char, int> > a(n);
    for(int i=0;i<n;i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    
    for(int i=0;i<n;i++) p[i] = a[i].ss;
    c[p[0]]=0;
    for(int i=1;i<n;i++)
        c[p[i]] = c[p[i-1]] + (a[i].ff!=a[i-1].ff);

    int k=0;
    while((1<<k) < n){
        vector< pair<pii, int> > a(n);
        for(int i=0;i<n;i++)
            a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
        sort(a.begin(), a.end());

        for(int i=0;i<n;i++) p[i] = a[i].ss;
        c[p[0]]=0;
        for(int i=1;i<n;i++)
            c[p[i]] = c[p[i-1]] + (a[i].ff!=a[i-1].ff);
        k++;
    }
    return p;
}