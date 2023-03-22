struct Lichao { // min
	struct line {
		ll a, b;
		array<int, 2> ch;
		line(ll a_ = 0, ll b_ = LLINF) : a(a_), b(b_), ch({-1, -1}) {}
		ll operator ()(ll x) { return a * x + b; }
	};
	vector<line> ln;

	int ch(int p, int d) {
		if (ln[p].ch[d] == -1) {
			ln[p].ch[d] = ln.size();
			ln.emplace_back();
		}
		return ln[p].ch[d];
	}
	Lichao() { ln.emplace_back(); }

	void add(line s, ll l=-N, ll r=N, int p=0) {
		ll m = (l+r)/2;
		bool L = s(l) < ln[p](l);
		bool M = s(m) < ln[p](m);
		bool R = s(r) < ln[p](r);
		if (M) swap(ln[p], s), swap(ln[p].ch, s.ch);
		if (s.b == LLINF) return;
		if (L != M) add(s, l, m-1, ch(p, 0));
		else if (R != M) add(s, m+1, r, ch(p, 1));
	}
	ll query(int x, ll l=-N, ll r=N, int p=0) {
		ll m = (l + r) / 2, ret = ln[p](x);
		if (ret == LLINF) return ret;
		if (x < m) return min(ret, query(x, l, m-1, ch(p, 0)));
		return min(ret, query(x, m+1, r, ch(p, 1)));
	}
};
