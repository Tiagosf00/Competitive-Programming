#define ti tuple<int, int, int>
struct Color{
    set<ti> inter; // l, r, color
    vector<ti> update(int l, int r, int c){
        if(inter.empty()){ inter.insert({l, r, c}); return {}; }
        vector<ti> removed;
        auto it = inter.lower_bound({l+1, 0, 0});
        it = prev(it);
        while(it != inter.end()){
            auto [l1, r1, c1] = *it;
            if((l<=l1 and l1<=r) or (l<=r1 and r1<=r) or (l1<=l and r<=r1)){
                removed.pb({l1, r1, c1});
            }else if(l1 > r)
                break;
            it = next(it);
        }
        for(auto [l1, r1, c1]: removed){
            inter.erase({l1, r1, c1});
            if(l1<l) inter.insert({l1, min(r1, l-1), c1});
            if(r<r1) inter.insert({max(l1, r+1), r1, c1});
        }
        if(c != 0) inter.insert({l, r, c});
        return removed;
    }

    ti query(int i){
        if(inter.empty()) return {INF, INF, INF};
        return *prev(inter.lower_bound({i+1, 0, 0}));
    }
};