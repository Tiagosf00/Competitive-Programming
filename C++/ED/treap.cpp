// source: https://github.com/victorsenam/caderno/blob/master/code/treap.cpp
//const int N = ; typedef int num;
num X[N]; int en = 1, Y[N], sz[N], L[N], R[N];
void calc (int u) { // update node given children info
	if(!u) return;
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	// code here, no recursion
}
void unlaze (int u) {
	if(!u) return;
	// code here, no recursion
}
void split_val(int u, num x, int &l, int &r) { // l gets <= x, r gets > x
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(X[u] <= x) { split_val(R[u], x, l, r); R[u] = l; l = u; }
	else { split_val(L[u], x, l, r); L[u] = r; r = u; }
	calc(u);
}
void split_sz(int u, int s, int &l, int &r) { // l gets first s, r gets remaining
	unlaze(u); if(!u) return (void) (l = r = 0);
	if(sz[L[u]] < s) { split_sz(R[u], s - sz[L[u]] - 1, l, r); R[u] = l; l = u; }
	else { split_sz(L[u], s, l, r); L[u] = r; r = u; }
	calc(u);
}
int merge(int l, int r) { // els on l <= els on r
	unlaze(l); unlaze(r); if(!l || !r) return l + r; int u;
	if(Y[l] > Y[r]) { R[l] = merge(R[l], r); u = l; }
	else { L[r] = merge(l, L[r]); u = r; }
	calc(u); return u;
}
void init(int n=N-1) { // XXX call before using other funcs
	for(int i = en = 1; i <= n; i++) { Y[i] = i; sz[i] = 1; L[i] = R[i] = 0; }
	random_shuffle(Y + 1, Y + n + 1);
}
void insert(int &u, int it){
	unlaze(u);
	if(!u) u = it;
	else if(Y[it] > Y[u]) split_val(u, X[it], L[it], R[it]), u = it;
	else insert(X[it] < X[u] ? L[u] : R[u], it);
	calc(u);
}
void erase(int &u, num key){
	unlaze(u);
	if(!u) return;
	if(X[u] == key) u = merge(L[u], R[u]);
	else erase(key < X[u] ? L[u] : R[u], key);
	calc(u);
}
int create_node(num key){
	X[en] = key;
	sz[en] = 1;
	L[en] = R[en] = 0;
	return en++;
}
int query(int u, int l, int r){//0 index
	unlaze(u);
	if(u! or r < 0 or l >= sz[u]) return identity_element;
	if(l <= 0 and r >= sz[u] - 1) return subt_data[u];
	int ans = query(L[u], l, r);
	if(l <= sz[ L[u] ] and sz[ L[u] ] <= r)
		ans = max(ans, st[u]);
	ans = max(ans, query(R[u], l-sz[L[u]]-1, r-sz[L[u]]-1));
	return ans;
}
