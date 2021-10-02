// heavily based on https://ideone.com/YQX9jv,
// which adamant cites here https://codeforces.com/blog/entry/13959?#comment-196033
struct Eertree {
	int s[N];
	int n, last, sz;

	int len[N], link[N];
	int to[N][A];

	Eertree() {
		s[n++] = -1;
		len[1] = -1, link[1] = 1; // "backspace" root is 1
		len[0] = 0, link[0] = 1;  // empty root is 0 (to[backspace root][any char] = empty root)
		last = 2;
		sz = 2;
	}

	int get_link(int u) {
		while (s[n - len[u] - 2] != s[n - 1]) u = link[u];
		return u;
	} 

	void push(int c) {
		s[n++] = c;
		int p = get_link(last);
		if (!to[p][c]) {
			int u = ++sz;
			len[u] = len[p] + 2;
			link[u] = to[get_link(link[p])][c]; // may be 0 (empty), but never 1 (backspace)
			to[p][c] = u;
		}
		last = to[p][c];
	}
};
