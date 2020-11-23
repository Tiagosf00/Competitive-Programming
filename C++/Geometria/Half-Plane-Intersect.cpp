// Half plane intersect O(n3)
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