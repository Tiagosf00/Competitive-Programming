bool inside(vector<point> vet, point ext) //ccw
{
    int l=2, r=(int)vet.size()-1;
    int res=r;
    while(l<r){
        int mid = (l+r)/2;
        if(esq(vet[0], vet[mid], ext)==-1){
            l=mid+1;
        }else
        {
            r=mid;
            res=mid;
        }
    }
    int a = esq(vet[0], vet[res-1], ext);
    int b = esq(vet[res-1], vet[res], ext);
    int c = esq(vet[res], vet[0], ext);

    if((a==1 or b==1 or c==1) and (a==-1 or b==-1 or c==-1)) return false;
    else return true;
}
