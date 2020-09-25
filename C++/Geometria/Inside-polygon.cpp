bool insideT(point a, point b, point c, point e){
    int x = ccw(a, b, e);
    int y = ccw(b, c, e);
    int z = ccw(c, a, e);
    return !((x==1 or y==1 or z==1) and (x==-1 or y==-1 or z==-1));
}

bool inside(vector<point> &vet, point e) //ccw
{
    int l=2, r=(int)vet.size()-1;
    int res=r;
    while(l<r){
        int mid = (l+r)/2;
        if(ccw(vet[0], vet[mid], e)==1)
            l=mid+1;
        else{
            r=mid;
            res=mid;
        }
    }

    return insideT(vet[0], vet[res-1], vet[res], e);
}
