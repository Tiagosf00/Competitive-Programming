vp mk(const vp &a,const vp &b){
    int i = 0, j = 0;
    for(int k = 0; k < (int)a.size(); k++)if(a[k]<a[i])
        i = k;
    for(int k = 0; k < (int)b.size(); k++)if(b[k]<b[j])
        j = k;

    vp c;
    c.reserve(a.size() + b.size());
    for(int k = 0; k < int(a.size()+b.size()); k++){
        point pt{a[i] + b[j]};
        if((int)c.size() >= 2 and !ccw(c[c.size()-2], c.back(), pt))
            c.pop_back();
        c.pb(pt);
        int q = i+1, w = j+1;
        if(q == int(a.size())) q = 0;
        if(w == int(b.size())) w = 0;
        if(ccw(c.back(), a[i]+b[w], a[q]+b[j]) < 0) i = q;
        else j = w;
    }

    if(!ccw(c[0], c[(int)c.size()-1], c[(int)c.size()-2]))
        c.pop_back();
    if(!ccw(c.back(), c[0], c[1])){
        c[0]=c.back();
        c.pop_back();
    }
    c.shrink_to_fit();

    return c;
}