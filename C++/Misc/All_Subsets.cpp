vi a, subset;
vector<vi> subsets;

// Iterative
void search(int k){
    if(k==(int)a.size())
        subsets.pb(subset);
    else{
        search(k+1);
        subset.pb(a[k]);
        search(k+1);
        subset.pop_back();
    }
}
search(0);

// Binary
for(int b=0;b<(1<<n);b++){
    vi subset;
    for(int i=0;i<n;i++)
        if(b&(1<<i)) subset.pb(a[i]);
    subsets.pb(subset);
}