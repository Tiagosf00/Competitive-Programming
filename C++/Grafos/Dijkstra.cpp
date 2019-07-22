// Dijkstra - Shortest Path

vii grafo[MAX];
int distancia[MAX];
bool visitado[MAX];
priority_queue< pii, vii, greater<pii> > fila;

void dijkstra(int k)
{
	int dist, vert, aux;
	distancia[k]=0;

	fila.push(mp(0,k));

	while(!fila.empty())
	{
		aux=fila.top().s;
		fila.pop();

		if(!visitado[aux])
		{
			visitado[aux]=true;
			forn(i, grafo[aux].size())
			{
				dist=grafo[aux][i].f;
				vert=grafo[aux][i].s;
				if(distancia[vert]>distancia[aux]+dist)
				{
					distancia[vert]=distancia[aux]+dist;
					fila.push(mp(distancia[vert], vert));	
				}
			}
		}
	}
}