// Dijkstra - Shortest Path

#define pii pair<int, int>
#define vi vector<int>
#define vii vector< pair<int,int> >
#define INF 0x3f3f3f3f

vector<vii> grafo(N+1, vii());
vi distancia(N+1, INF);
priority_queue< pii, vii, greater<pii> > fila;

void dijkstra(int k){
	int dist, vert, aux;
	distancia[k]=0;

	fila.push(mp(k, 0));

	while(!fila.empty()){
		aux=fila.top().f;
		fila.pop();

		for(auto v: grafo[aux]){
			vert=v.f;
			dist=v.s;
			if(distancia[vert]>distancia[aux]+dist){
				distancia[vert]=distancia[aux]+dist;
				fila.push(mp(vert, distancia[vert]));	
			}
		}
	}
}

int main()
{
	for(int i=0; i<M; i++){
		cin >> a >> b >> p;
		grafo[a].pb(mp(b, p));
		grafo[b].pb(mp(a, p));
	}
}
