#define vi vector<int>

vector< vector<int> > grafo;
vector<bool> visited;
vi t, low;
int timer=0;

void find_bridges(int v, int p=-1)
{
	visited[v] = true;
	t[v] = low[v] = timer++;
	for(int i=0;i<(int)grafo[v].size();i++)
	{
		int vert = grafo[v][i];
		if(vert == p)
			continue;
		if(visited[vert])
			low[v] = min(low[v], t[vert]);
		else
		{
			find_bridges(vert, v);
			low[v] = min(low[v], low[vert]);
			if(low[to] > t[v])
				IS_BRIDGE(v, vert);
		}
	}
}

int main()
{
	timer = 0;
	visited.assign(N+1, false);
	t.assign(N+1, 0);
	low.assign(N+1, 0);

	for(int i=0;i<N;i++)
		if(!visited[i])
			find_bridges(1);

	return 0;
}