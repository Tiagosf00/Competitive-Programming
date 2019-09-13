typedef struct
{
	pii prefix, sufix, total, maximo; 
} no;

int noleft[MAX], noright[MAX]; //Guarda os valores dos nos para que nao sejam calculados novamente nas querys
int v[MAX];
no arvore[MAX];

pii somar(pii a, pii b) // une pairs
{
	return mp(a.f+b.f, a.s+b.s);
}

no une(no l, no r)
{
	if(l.total.s==0)
		return r;
	if(r.total.s==0)
		return l;

	no m;

	m.prefix = max(l.prefix, somar(l.total, r.prefix)); //prefixo
	m.sufix = max(r.sufix, somar(r.total, l.sufix)); //sufixo
	m.total = somar(l.total, r.total); //Soma de todos os elementos da subarvore
	m.maximo = max(max(l.maximo, r.maximo), somar(l.sufix, r.prefix)); //Resultado para cada subarvore

	return m;
}

no makenozero()
{
	no m;
	m.prefix=m.sufix=m.total=m.maximo=mp(0,0);
	return m;
}

no makeno(int k)
{
	no m;
	m.prefix=m.sufix=m.total=m.maximo=mp(k,1);
	return m;
}

void monta(int n)
{
	if(noleft[n]==noright[n])
	{
		arvore[n]=makeno(v[noleft[n]]);
		return;
	}

	int mid = (noleft[n]+noright[n])/2;
	noleft[2*n]=noleft[n]; noright[2*n]=mid;
	noleft[2*n+1]=mid+1; noright[2*n+1]=noright[n];

	monta(2*n);
	monta(2*n+1);

	arvore[n]=une(arvore[2*n], arvore[2*n+1]);
}

no busca(int n, int esq, int dir)
{
	if(noleft[n]>=esq and noright[n]<=dir)
		return arvore[n];
	if(noright[n]<esq or noleft[n]>dir)
		return makenozero();

	return une(busca(2*n, esq, dir),busca(2*n+1, esq, dir));
}

int main()
{
	int T, N, Q, A, B;
	no aux;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		for(int i=1;i<=N;i++)
			scanf("%d", &v[i]); //Elementos da arvore

		noleft[1]=1;noright[1]=N;
		monta(1);

		cin >> Q;
		while(Q--)
		{
			scanf("%d%d", &A, &B); //Intervalo da query
			aux = busca(1, A, B);
			printf("%d %d\n", aux.maximo.f, aux.maximo.s);
		}
	}


	return 0;
}
