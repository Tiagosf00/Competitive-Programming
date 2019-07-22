//BFS (Breadth First Search) O(V+A)

void BFS(int x)
{
	int atual, v, u;
	queue<int> fila;
	fila.push(x);

	componente[x] = valor;
	atual = 0;
	while(!fila.empty())
	{
		v = fila.front();
		fila.pop();

		for(int i = 0;i < (int)vizinhos[v].size();i++)
		{
			u = vizinhos[v][i];
			if(componente[u] == -1)
			{
				componente[u] = componente[v];
				fila.push(u);
			}
		}
	}
}