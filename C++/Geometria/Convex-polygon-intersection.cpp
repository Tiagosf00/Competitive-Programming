cod cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}

int ccw(point a, point b, point e) //-1=esq; 0=collinear; 1=dir;
{
    cod tmp = cross(b-a, e-a); // from a to b
    return (tmp > EPS) - (tmp < -EPS);
}

int n=4;
vector<point> A, B;

bool intersect()
{
    A.pb(A[0]);
    B.pb(B[0]);
    point centerA=point();
    point centerB=point();

    for(int i=0;i<n;i++)
    {
        centerA=centerA+A[i];
        centerB=centerB+B[i];
    }
    centerA=centerA/n;
    centerB=centerB/n;
    A.pb(centerA);
    B.pb(centerB);


    bool d, e;

    for(int j=1;j<n+2;j++)
    {
        d=false, e=false;
        for(int i=0;i<n;i++)
        {
            int t = esq(A[i], A[i+1], B[j]);
            if(t==1) e=true;
            else if(t==-1) d=true;
        }

        if(!(e and d))
            return 1;
    }


    for(int j=1;j<n+2;j++)
    {
        d=false, e=false;
        for(int i=0;i<n;i++)
        {
            int t = esq(B[i], B[i+1], A[j]);
            if(t==1) e=true;
            else if(t==-1) d=true;
        }

        if(!(e and d))
            return 1;
    }

    return 0;
}