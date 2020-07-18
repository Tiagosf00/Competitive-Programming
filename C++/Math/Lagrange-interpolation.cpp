// Lagrange's interpolation (n+1 points)
ld interpolate(vii d, ld x){
    ld y = 0;
    int n = d.size();
    for(int i=0;i<n;i++){
        ld yi = d[i].ss;
        for(int j=0;j<n;j++)
            if(j!=i)
               yi = yi*(x - d[j].ff)/(ld)(d[i].ff - d[j].ff);

        y += yi;
    }
    return y;
}

ld inv_interpolate(vii d, ld y){
    ld x = 0;
    int n = d.size();
    for(int i=0;i<n;i++){
        ld xi = d[i].ff;
        for(int j=0;j<n;j++)
            if(j!=i)
                xi = xi*(y - d[j].ss)/(ld)(d[i].ss - d[j].ss);

        x += xi;
    }
    return x;
}