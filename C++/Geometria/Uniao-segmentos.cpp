int length_union(const vector<pii> &a){
    int n = a.size();
    vector<pair<int, bool>> x(n*2);
    for(int i = 0; i < n; i++){
        x[i*2] = {a[i].ff, false};
        x[i*2+1] = {a[i].ss, true};
    }

    sort(x.begin(), x.end());

    int result=0;
    int c=0;
    for(int i=0;i<2*n;i++){
        if(i and c and x[i].ff>x[i-1].ff)
            result += x[i].ff-x[i-1].ff;

        if(x[i].ss) c--;
        else c++;
    }
    return result;
}