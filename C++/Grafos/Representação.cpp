// Grafos

// Lista de arestas

	vector< pair<int, int> > arestas;
	arestas.push_back(make_pair(1, 2));
	arestas.push_back(make_pair(1, 3));

// Matriz de Adjacência

	int grafo[10][10]; //bool se for sem peso

	grafo[1][2] = grafo[2][1] = 1;
	grafo[1][3] = grafo[3][1] = 2;

// Lista de Adjacência 

	vector<int> vizinhos[10];

	vizinhos[1].push_back(2);
	vizinhos[1].push_back(2);