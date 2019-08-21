// Union-Find Functions

int pai[MAX], peso[MAX];

int find(int aux)
{
	if(pai[aux]==aux)
		return aux;
	else
		return pai[aux]=find(pai[aux], pai);
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);
			
	if(pesos[x]<pesos[y])
		pai[x] = y;
	else if(pesos[x]>pesos[y])
		pai[y] = x;
	else if(pesos[x]==pesos[y])
	{
		pai[x] = y;
		pesos[y]++;
	}
}

int main()
{
	for(int i=1;i<=N;i++)
		pai[i]=i;
}