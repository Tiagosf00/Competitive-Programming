vp minkowski(vp p, vp q){
    int n = p.size(), m = q.size();
    auto reorder = [&](vp &p) {
        // set the first vertex must be the lowest
        int id = 0;
        for(int i=1;i<p.size();i++){
            if(p[i].y < p[id].y or (p[i].y == p[id].y and p[i].x < p[id].x))
                id = i;
        }
        rotate(p.begin(), p.begin() + id, p.end());
    };

    reorder(p); reorder(q);
    p.push_back(p[0]);
    q.push_back(q[0]);
    vp ans; int i = 0, j = 0;
    while(i < n or j < m){
        ans.push_back(p[i] + q[j]);
        cod cross = (p[i+1] - p[i]) ^ (q[j+1] - q[j]);
        if(cross >= 0) i ++;
        if(cross <= 0) j ++;
    }
    return ans;
}