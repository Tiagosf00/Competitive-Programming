// Polygon Cut length
ld solve(vp &p, point a, point b){ // ccw
    int n = p.size();
    ld ans = 0;
 
    for(int i=0;i<n;i++){
        int j = (i+1) % n;
 
        int signi = ccw(a, b, p[i]);
        int signj = ccw(a, b, p[j]);
 
        if(signi == 0 and signj == 0){
            if((b-a) * (p[j]-p[i]) > 0){
                ans += param(a, b, p[j]);
                ans -= param(a, b, p[i]);
            }
        }else if(signi <= 0 and signj > 0){
            ans -= param(a, b, inter_line({a, b}, {p[i], p[j]})[0]);
        }else if(signi > 0 and signj <= 0){
            ans += param(a, b, inter_line({a, b}, {p[i], p[j]})[0]);
        }
    }
 
    return abs(ans * norm(b-a));
}