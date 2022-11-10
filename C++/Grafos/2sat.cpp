#define rep(i,l,r) for (int i = (l); i < (r); i++)
struct TwoSat { // copied from kth-competitive-programming/kactl
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true
	TwoSat(int n = 0) : N(n), gr(2*n) {}
	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}
	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void atMostOne(const vi& li) { // (optional)
		if ((int)li.size() <= 1) return;
		int cur = ~li[0];
		rep(i,2,(int)li.size()) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}
	vi _val, comp, z; int time = 0;
	int dfs(int i) {
		int low = _val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, _val[e] ?: dfs(e));
		if (low == _val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return _val[i] = low;
	}
	bool solve() {
		values.assign(N, -1);
		_val.assign(2*N, 0); comp = _val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};
