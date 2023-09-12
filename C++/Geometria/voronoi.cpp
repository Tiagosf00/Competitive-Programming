bool polygonIntersection(line &seg, vp &p) {
    long double l = -1e18, r = 1e18;
    for(auto ps : p) {
        long double z = seg.eval(ps);
        l = max(l, z);
        r = min(r, z);
    }
    return l - r > EPS;
}

int w, h;

line getBisector(point a, point b) {
    line ans(a, b);
    swap(ans.a, ans.b);
    ans.b *= -1;
    ans.c = ans.a * (a.x + b.x) * 0.5 + ans.b * (a.y + b.y) * 0.5;
    return ans;
}

vp cutPolygon(vp poly, line seg) {
    int n = (int) poly.size();
    vp ans;
    for(int i = 0; i < n; i++) {
        double z = seg.eval(poly[i]);
        if(z > -EPS) {
            ans.push_back(poly[i]);
        }
        double z2 = seg.eval(poly[(i + 1) % n]);
        if((z > EPS && z2 < -EPS) || (z < -EPS && z2 > EPS)) {
            ans.push_back(inter_line(seg, line(poly[i], poly[(i + 1) % n]))[0]);
        }
    }
    return ans;
}

// BE CAREFUL!
// the first point may be any point
// O(N^3)
vp getCell(vp pts, int i) {
    vp ans;
    ans.emplace_back(0, 0);
    ans.emplace_back(1e6, 0);
    ans.emplace_back(1e6, 1e6);
    ans.emplace_back(0, 1e6);
    for(int j = 0; j < (int) pts.size(); j++) {
        if(j != i) {
            ans = cutPolygon(ans, getBisector(pts[i], pts[j]));
        }
    }
    return ans;
}

// O(N^2) expected time
vector<vp> getVoronoi(vp pts) {
    // assert(pts.size() > 0);
    int n = (int) pts.size();
    vector<int> p(n, 0);
    for(int i = 0; i < n; i++) {
        p[i] = i;
    }
    shuffle(p.begin(), p.end(), rng);
    vector<vp> ans(n);
    ans[0].emplace_back(0, 0);
    ans[0].emplace_back(w, 0);
    ans[0].emplace_back(w, h);
    ans[0].emplace_back(0, h);
    for(int i = 1; i < n; i++) {
        ans[i] = ans[0];
    }
    for(auto i : p) {
        for(auto j : p) {
            if(j == i) break;
            auto bi = getBisector(pts[j], pts[i]);
            if(!polygonIntersection(bi, ans[j])) continue;
            ans[j] = cutPolygon(ans[j], getBisector(pts[j], pts[i]));
            ans[i] = cutPolygon(ans[i], getBisector(pts[i], pts[j]));
        }
    }
    return ans;
}
