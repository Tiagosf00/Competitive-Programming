pair<point, point> polygon_diameter(vp p) {
    p = convex_hull(p);
	int n = p.size(), j = n<2 ? 0:1;
	pair<ll, vp> res({0, {p[0], p[0]}});
	for (int i=0;i<j;i++){
		for (;; j = (j+1) % n) {
			res = max(res, {norm2(p[i] - p[j]), {p[i], p[j]}});
			if ((p[(j + 1) % n] - p[j]) ^ (p[i + 1] - p[i]) >= 0)
				break;
		}
	}
	return res.second;
}

double diameter(const vector<point> &p) {
    vector<point> h = convexHull(p);
    int m = h.size();
    if (m == 1)
        return 0;
    if (m == 2)
        return dist(h[0], h[1]);
    int k = 1;
    while (area(h[m - 1], h[0], h[(k + 1) % m]) > area(h[m - 1], h[0], h[k]))
        ++k;
    double res = 0;
    for (int i = 0, j = k; i <= k && j < m; i++) {
        res = max(res, dist(h[i], h[j]));
        while (j < m && area(h[i], h[(i + 1) % m], h[(j + 1) % m]) > area(h[i], h[(i + 1) % m], h[j])) {
            res = max(res, dist(h[i], h[(j + 1) % m]));
            ++j;
        }
    }
    return res;
}
