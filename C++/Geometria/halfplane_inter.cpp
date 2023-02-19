struct Halfplane {
    point p, pq;
    ld angle;
    Halfplane() {}
    Halfplane(const point &a, const point &b) : p(a), pq(b - a) {
        angle = atan2l(pq.y, pq.x);
    }

    bool out(const point &r) { return (pq ^ (r - p)) < -EPS; }
    bool operator<(const Halfplane &e) const { return angle < e.angle; }

    friend point inter(const Halfplane &s, const Halfplane &t) {
        ld alpha = ((t.p - s.p) ^ t.pq) / (s.pq ^ t.pq);
        return s.p + (s.pq * alpha);
    }
};

vp hp_intersect(vector<Halfplane> &H) {

    point box[4] = {
        point(LLINF, LLINF),
        point(-LLINF, LLINF),
        point(-LLINF, -LLINF),
        point(LLINF, -LLINF)
    };

    for(int i = 0; i < 4; i++) {
        Halfplane aux(box[i], box[(i+1) % 4]);
        H.push_back(aux);
    }

    sort(H.begin(), H.end());
    deque<Halfplane> dq;
    int len = 0;
    for(int i = 0; i < (int)H.size(); i++) {

        while (len > 1 && H[i].out(inter(dq[len-1], dq[len-2]))) {
            dq.pop_back();
            --len;
        }

        while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
            dq.pop_front();
            --len;
        }

        if (len > 0 && fabsl((H[i].pq ^ dq[len-1].pq)) < EPS) {
            if ((H[i].pq * dq[len-1].pq) < 0.0)
                return vp();

            if (H[i].out(dq[len-1].p)) {
                dq.pop_back();
                --len;
            }
            else continue;
        }

        dq.push_back(H[i]);
        ++len;
    }

    while (len > 2 && dq[0].out(inter(dq[len-1], dq[len-2]))) {
        dq.pop_back();
        --len;
    }

    while (len > 2 && dq[len-1].out(inter(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }

    if (len < 3) return vp();

    vp ret(len);
    for(int i = 0; i+1 < len; i++) {
        ret[i] = inter(dq[i], dq[i+1]);
    }
    ret.back() = inter(dq[len-1], dq[0]);
    return ret;
}

// O(n3)
vp half_plane_intersect(vector<line> &v){
    vp ret;
    int n = v.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            point crs = inter(v[i], v[j]);
            if(crs.x == INF) continue;
            bool bad = 0;
            for(int k=0; k<n; k++)
                if(v[k].eval(crs) < -EPS){
                    bad = 1;
                    break;
                }
            
            if(!bad) ret.push_back(crs);
        }
    }
    return ret;
}