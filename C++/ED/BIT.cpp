// (BIT) Fenwick Tree

int N, bit[MAX];

int soma(int x)
{
    int resp=0;

    // for(int i=x;i>0;i-=i&-i)
    //     resp+=bit[i];

    while(x > 0)
    {
        resp += bit[x];
        x -= (x & -x);
    }

    return resp;
}

int query(int L, int R)
{
	return soma(R)-soma(L-1);
}

void update(int x, int v) // add v in x
{
    // for(;x<=n;x+=x&-x)
    //       bit[x] += v;

    while(x <= N)
    {
        bit[x] += v;
        x += (x & -x);
    }
}
