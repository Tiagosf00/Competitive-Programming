// Kruskal -  Minimum Spanning Tree

typedef struct
{
	int A, B;
	int dist;
} vertice;

vertice grafo[MAX];
int pai[MAX];

int find(int X) // Union-Find
{
	if(pai[X]==X)
		return X;
	else
		return pai[X]=find(pai[X]);
}

void join(int X, int Y)
{
	int paix = find(X);
	int paiy = find(Y);
	pai[paix]=paiy;
}

bool comp(vertice A, vertice B)
{
	return A.dist < B.dist;
}

void kruskal()
{	
	for(int i=1;i<=N;i++)
		pai[i]=i;

	for(int i=1;i<=M;i++)
		cin >> grafo[i].A >> grafo[i].B >> grafo[i].dist;
		
	sort(grafo+1, grafo+M+1, comp);

	for(int i=1;i<M;i++)
	{
		if(find(grafo[i].A)!=find(grafo[i].B))
		{
			join(grafo[i].A, grafo[i].B);
			soma+=grafo[i].dist;
		}
	}

	cout << soma << endl;
}
