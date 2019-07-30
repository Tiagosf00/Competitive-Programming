// Árvore de Indexação Binária (BIT) Árvore de Fenwick

//Exemplo - Soma em intervalo

int bit[MAX];

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

int query(int L, R)
{
	return soma(R)-soma(L);
}

void atualiza(int x, int v) // adiciona v no indice x
{
    // for(;x<=n;x+=x&-x)
    //       bit[x] += v;

    while(x <= N)
    {
        bit[x] += v;
        x += (x & -x);
    }
}