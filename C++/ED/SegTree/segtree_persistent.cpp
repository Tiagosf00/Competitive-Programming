// botar aquele bagulho de botar tipo T?
struct ST {    
    int left[120*N], right[120*N];
    int t[120*N];
    int idx = 1;
    int id = INF;

    int f(int a, int b) {
        return min(a, b);
    }

    // Testar esse build!!!
    int build(vector<int>& v, int lx = 0, int rx = N-1) {
        int y = idx++;
        if(rx == lx) {
            if(lx < (int)v.size())
                t[y] = v[lx];
            else
                t[y] = id;
            return y;
        }

        int mid = (lx+rx)/2;
        int yl = build(v, lx, mid);
        int yr = build(v, mid+1, rx);

        left[y] = yl;
        right[y] = yr;
        t[y] = f(t[left[y]], t[right[y]]);

        return y;
    }

    int query(int l, int r, int x, int lx = 0, int rx = N-1) {
        if(l <= lx and rx <= r) return t[x];
        if(r < lx or rx < l) return id;

        int mid = (lx+rx)/2;
        auto s1 = query(l, r, left[x], lx, mid);
        auto s2 = query(l, r, right[x], mid+1, rx);
        return f(s1, s2);
    }

    int update(int i, int val, int x, int lx = 0, int rx = N-1) {
        int y = idx++;
        if(lx == rx) {
            t[y] = val;
            return y;
        }

        int mid = (lx+rx)/2;
        if(lx <= i and i <= mid) {
            int k = update(i, val, left[x], lx, mid);
            left[y] = k;
            right[y] = right[x];
        }
        else {
            int k = update(i, val, right[x], mid+1, rx);
            left[y] = left[x];
            right[y] = k;
        }

        t[y] = f(t[left[y]], t[right[y]]);
        return y;
    }
};