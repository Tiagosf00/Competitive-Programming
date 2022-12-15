vector<int> g[N], gt[N], T[N];
vector<int> S;
int dsu[N], label[N];
int sdom[N], idom[N], dfs_time, id[N];

vector<int> bucket[N];
vector<int> down[N];

void prep(int u){
	S.push_back(u);
	id[u] = ++dfs_time;
	label[u] = sdom[u] = dsu[u] = u;

	for(int v : g[u]){
		if(!id[v])
			prep(v), down[u].push_back(v);
		gt[v].push_back(u);
	}
}

int fnd(int u, int flag = 0){
	if(u == dsu[u]) return u;
	int v = fnd(dsu[u], 1), b = label[ dsu[u] ];
	if(id[ sdom[b] ] < id[ sdom[ label[u] ] ])
		label[u] = b;
	dsu[u] = v;
	return flag ? v : label[u];
}

void build_dominator_tree(int root, int sz){
	// memset(id, 0, sizeof(int) * (sz + 1));
	// for(int i = 0; i <= sz; i++) T[i].clear();
	prep(root);
	reverse(S.begin(), S.end());

	int w;
	for(int u : S){
		for(int v : gt[u]){
			w = fnd(v);
			if(id[ sdom[w] ] < id[ sdom[u] ])
				sdom[u] = sdom[w];
		}
		gt[u].clear();

		if(u != root) bucket[ sdom[u] ].push_back(u);

		for(int v : bucket[u]){
			w = fnd(v);
			if(sdom[w] == sdom[v]) idom[v] = sdom[v];
			else idom[v] = w;
		}
		bucket[u].clear();

		for(int v : down[u]) dsu[v] = u;
		down[u].clear();
	}

	reverse(S.begin(), S.end());
	for(int u : S) if(u != root){
		if(idom[u] != sdom[u]) idom[u] = idom[ idom[u] ];
		T[ idom[u] ].push_back(u);
	}
	S.clear();
}
