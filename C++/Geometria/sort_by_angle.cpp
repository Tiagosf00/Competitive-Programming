int quarter(point a)
{
    if(a.x>0 and a.y>=0) return 0;
    if(a.x<=0 and a.y>0) return 1;
    if(a.x<0 and a.y<=0) return 2;
    return 3;
}

point c;
bool comp(point a, point b) //ccw
{
    a=a-c;b=b-c;
    int qa = quarter(a);
    int qb = quarter(b);
    if(qa==qb)
        return (a^b)>0;
    else
        return qa<qb;
}

c = center(A);


// only vectors in range [x+0, x+180)
bool comp(point a, point b){
    return (a ^ b) > 0; // ccw
    // return (a ^ b) < 0; // cw
}
