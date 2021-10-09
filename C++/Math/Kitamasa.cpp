using poly = vector<mint>; // mint = int mod P with operators +, - and *
inline int len(const poly& a) { return a.size(); } // get rid of the annoying "hey a.size() is unsigned" warning

poly pmul(const poly& a, const poly& b) {
	poly c(len(a) + len(b) - 1, 0);
	for (int i = 0; i < len(a); i++)
		for (int j = 0; j < len(b); j++)
			c[i+j] = c[i+j] + a[i] * b[j];
	return c;
}

// only works if b.back() == 1
poly pmod(const poly& a, const poly& b) {
	poly c(a.begin(), a.end());
	for (int i = len(c) - 1; i >= len(b) - 1; i--) {
		int k = i - (len(b) - 1); // index of the quotient term
		for (int j = 0; j < len(b); j++)
			c[j+k] = c[j+k] - c[i] * b[j];
	}
	c.resize(len(b) - 1);
	return c;
}

poly ppwr(poly x, ll e, poly f) {
	poly ans = { 1 };
	for (; e > 0; e /= 2) {
		if (e & 1) ans = pmod(pmul(ans, x), f);
		x = pmod(pmul(x, x), f);
	}
	return ans;
}

// values = { A0, A1, ..., An }. recurrence = C0 × A0 + C1 × A1 + ... + Cn × An generates A{n+1}
mint kitamasa(const poly& values, const poly& recurrence, ll n) {
	poly f(len(recurrence) + 1);
	f.back() = 1;
	for (int i = 0; i < len(recurrence); i++)
		f[i] = mint(0) - recurrence[i];

	auto d = ppwr(poly{0, 1}, n, f); // x^N mod f(x)

	mint ans = 0;
	for (int i = 0; i < len(values); i++)
		ans = ans + d[i] * values[i];
	return ans;
}
