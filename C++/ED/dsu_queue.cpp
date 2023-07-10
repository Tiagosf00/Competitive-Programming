// DSU with queue rollback
// Normal DSU implementation with queue-like rollback, pop removes the oldest join.
// find(x) - O(logn)
// join(a, b) - O(logn)
// pop() - (log^2n) amortized

struct event {
    int a, b;    // original operation
    int fa, fb; // fa turned into fb's father
    bool type; // 1 = inverted, 0 = normal
};

struct DSU {
    int n;
    vector<int> parent, size;
    vector<event> st; int qnt_inv;
    DSU(int n): n(n), parent(n), size(n, 1), qnt_inv(0) {
        for (int i=0;i<n;i++) parent[i] = i;
    }

    int find(int a) {
        if (parent[a] == a) return a;
        return find(parent[a]);
    }

    void join(int a, int b, bool inverted=false) {
        int fa = find(a), fb = find(b);
        if (size[fa] < size[fb]) swap(fa, fb);
        st.push_back({a, b, fa, fb, inverted});
        if (inverted == 1) qnt_inv++;
        if (fa != fb) {
            parent[fb] = fa;
            size[fa] += size[fb];
        }
    }

    void roll_back() {
        auto [a, b, fa, fb, type] = st.back(); st.pop_back();
        if (type == 1) qnt_inv--;
        if (fa != fb) {
            parent[fb] = fb;
            size[fa] -= size[fb];
        }
    }

    void pop() {
        auto lsb = [](int x) { return x&-x; };
        if (qnt_inv == 0) { // invert all elements
            vector<event> normal;
            while (!st.empty()) {
                normal.push_back(st.back());
                roll_back();
            }
            for (auto [a, b, fa, fb, type]: normal) {
                join(a, b, true);
            }
        } else if (st.back().type == 0) { // need to realocate
            int qnt = lsb(qnt_inv);
            vector<event> normal, inverted;
            while (qnt > 0) {
                event e = st.back();
                if (e.type == 1) {
                    inverted.push_back(e);
                    qnt --;
                } else {
                    normal.push_back(e);
                }
                roll_back();
            }
            while (!normal.empty()) {
                auto [a, b, fa, fb, type] = normal.back(); normal.pop_back();
                join(a, b);
            }
            while (!inverted.empty()) {
                auto [a, b, fa, fb, type] = inverted.back(); inverted.pop_back();
                join(a, b, true);
            }
        }

        // remove the last element
        roll_back();
    }
};