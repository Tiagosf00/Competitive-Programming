int quarter(point a)
{
    if(a.x>=0 and a.y>0) return 0;
    if(a.x<0 and a.y>=0) return 1;
    if(a.x<=0 and a.y<0) return 2;
    return 3;
}

bool comp(point a, point b)
{
    int qa = quarter(a);
    int qb = quarter(b);
    if(qa==qb)
        return cross(a,b)>0;
    else
        return quarter(a)<quarter(b);
}