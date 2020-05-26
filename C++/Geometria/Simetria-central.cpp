bool simetric(vector<point> &a){ //ordered
    int n = a.size();
    c = center(a);
    if(n&1) return false;
    for(int i=0;i<n/2;i++)
        if(!collinear(a[i], a[i+n/2], c))
            return false;
    return true;
}
