#define pii pair<int, int>

void radix_sort(vector<pii>& rnk, vi& ind) {
    auto counting_sort = [](vector<pii>& rnk, vi& ind) {
        int n = ind.size(), maxx = -1;
        for(auto p : rnk) maxx = max(maxx, p.ff);

        vi cnt(maxx+1, 0), pos(maxx+1), ind_new(n);
        for(auto p : rnk) cnt[p.ff]++;
        pos[0] = 0;

        for(int i = 1; i <= maxx; i++) {
            pos[i] = pos[i-1] + cnt[i-1];
        }

        for(auto idx : ind) {
            int val = rnk[idx].ff;
            ind_new[pos[val]] = idx;
            pos[val]++;
        }

        swap(ind, ind_new);
    };

    for(int i = 0; i < (int)rnk.size(); i++) swap(rnk[i].ff, rnk[i].ss);
    counting_sort(rnk, ind);
    for(int i = 0; i < (int)rnk.size(); i++) swap(rnk[i].ff, rnk[i].ss);
    counting_sort(rnk, ind);
}

vi suffix_array(const string& s) {
    int n = s.size();
    vector<pii> rnk(n, {0, 0});
    vi ind(n);
    for(int i=0;i<n;i++) {
        rnk[i].ff = (s[i] == '$') ? 0 : s[i]-'a'+1; // manter '$' como 0
        ind[i] = i;
    }

    for(int k = 1; k <= n; k = (k << 1)) {
        for(int i = 0; i < n; i++) {
            if(ind[i]+k >= n) {
                rnk[ind[i]].ss = 0;
            }
            else {
                rnk[ind[i]].ss = rnk[ind[i]+k].ff;
            }
        }
        radix_sort(rnk, ind); // sort(all(rnk), cmp) pra n*log(n), cmp com rnk[i] < rnk[j]

        vector<pii> tmp = rnk;
        tmp[ind[0]] = {1, 0}; // rnk.ff comecar em 1 pois '$' eh o 0
        for(int i = 1; i < n; i++) {
            tmp[ind[i]].ff = tmp[ind[i-1]].ff;
            if(rnk[ind[i]] != rnk[ind[i-1]]) {
                tmp[ind[i]].ff++;
            }
        }
        swap(rnk, tmp);
    }
    return ind;
}


vi lcp_array(const string& s, const vi& sarray) {
    vi inv(s.size());
    for(int i = 0; i < (int)s.size(); i++) {
        inv[sarray[i]] = i;
    }
    vi lcp(s.size());
    int k = 0;
    for(int i = 0; i < (int)s.size()-1; i++) {
        int pi = inv[i];
        if(pi-1 < 0) continue;
        int j = sarray[pi-1];

        while(s[i+k] == s[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1, 0);
    }

    return vi(lcp.begin()+1, lcp.end()); // LCP(i, j) = min(lcp[i], ..., lcp[j-1])
}
