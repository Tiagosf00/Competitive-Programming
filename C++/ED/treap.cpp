mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // mt19937_64
uniform_int_distribution<int> distribution(1, INF);

const int N = 2e5+10;
int nxt = 0;
int X[N], Y[N], L[N], R[N], sz[N], idx[N];
bool flip[N];

//! Call this before anything else
void build() {
    iota(Y+1, Y+N, 1);
	shuffle(Y+1, Y+N, rng); // rng :: mt19937
}

int new_node(int x, int id) {
	int u = ++nxt;
    idx[u] = id;
	sz[u] = 1;
	X[u] = x;
	return u;
}

void push(int u) { // also known as unlaze
    if(!u) return;
    if (flip[u]) {
		flip[u] = false;
		flip[L[u]] ^= 1;
		flip[R[u]] ^= 1;
		swap(L[u], R[u]);
	}
}

void pull(int u) { // also known as fix
	if (!u) return;
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
}

// root = merge(l, r);
int merge(int l, int r) {
	push(l); push(r);
	int u;
	if (!l || !r) {
		u = l ? l : r;
	} else if (Y[l] < Y[r]) {
		u = l;
		R[u] = merge(R[u], r);
	} else {
		u = r;
		L[u] = merge(l, L[u]);
	}
	pull(u);
	return u;
}

// (s elements, N - s elements)
pair<int, int> splitsz(int u, int s) {
	if (!u) return {0, 0};
	push(u);
	if (sz[L[u]] >= s) {
		auto [l, r] = splitsz(L[u], s);
		L[u] = r;
		pull(u);
		return { l, u };
	} else {
		auto [l, r] = splitsz(R[u], s - sz[L[u]] - 1);
		R[u] = l;
		pull(u);
		return { u, r };
	}
}

// (<= x, > x)
pair<int, int> splitval(int u, int x) {
	if (!u) return {0, 0};
	push(u);
	if (X[u] > x) {
		auto [l, r] = splitval(L[u], x);
        L[u] = r;
		pull(u);
		return { l, u };
	} else {
		auto [l, r] = splitval(R[u], x);
        R[u] = l;
		pull(u);
		return { u, r };
	}
}

int insert(int u, int node) {
    push(u);
    if (!u) return node;
    if (Y[node] < Y[u]) {
        tie(L[node], R[node]) = splitval(u, X[node]);
        u = node;
    }
    else if (X[node] < X[u]) L[u] = insert(L[u], node);
    else R[u] = insert(R[u], node);
    pull(u);
    return u;
}

int find(int u, int x) {
    return u == 0    ? 0 :
           x == X[u] ? u :
           x <  X[u] ? find(L[u], x) :
                       find(R[u], x);
}

void free(int u) { /* node u can be deleted, maybe put in a pool of free IDs */ }

int erase(int u, int key) {
    push(u);
    if (!u) return 0;
    if (X[u] == key) {
        int v = merge(L[u], R[u]);
        free(u);
        u = v; 
    } else u = erase(key < X[u] ? L[u] : R[u], key);
    pull(u);
    return u;
}
