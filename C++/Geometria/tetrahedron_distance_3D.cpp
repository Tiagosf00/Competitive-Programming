point proj(point a, point b){
    return b*(dot(a, b)/dot(b, b));
}
point projPontoReta(point p, point a, point b){
    return proj(p-a, b-a) + a;
}
point projPontoPlano(point p, point a, point b, point c){
    return p - proj(p-a, cross(b-a, c-a));
}


ld distPontoReta(point p, point a, point b){
    point d = b-a;
    point v = p-a;
    point dl = proj(v, d);
    if (dot(dl, dl)>dot(d, d) or dl.x*d.x<0 or dl.y*d.y<0 or dl.z*d.z<0)
        return LLINF;
    return abs(v-dl);
}

ld distPontoPlano(point p, point a, point b, point c){
    point pr = projPontoPlano(p, a, b, c);
    point d1, d2;
    d1 = projPontoReta(pr, b, c)-pr;
    d2 = projPontoReta(a, b, c)-a;
    if (d1.x*d2.x < 0 or d1.y*d2.y < 0 or d1.z*d2.z < 0 or dot(d2, d2)<dot(d1, d1))
        return LLINF;
    d1 = projPontoReta(pr, a, c)-pr;
    d2 = projPontoReta(b, a, c)-b;
    if (d1.x*d2.x < 0 or d1.y*d2.y < 0 or d1.z*d2.z < 0 or dot(d2, d2)<dot(d1, d1))
        return LLINF;
    d1 = projPontoReta(pr, b, a)-pr;
    d2 = projPontoReta(c, b, a)-c;
    if (d1.x*d2.x < 0 or d1.y*d2.y < 0 or d1.z*d2.z < 0 or dot(d2, d2)<dot(d1, d1))
        return LLINF;
    return abs(pr-p);
}


ld distRetaReta(point a1, point a2, point b1, point b2){
    point va = a2-a1;
    point vb = b2-b1;
    point d = (a1-b1) + proj(b1-a1, cross(va, vb));
    ld lambda1, lambda2;
    if (va.x*vb.y - vb.x*va.y!=0.0)
        lambda1 = (vb.x*d.y - d.x*vb.y)/(va.x*vb.y - vb.x*va.y);
    else if (va.x*vb.z - vb.x*va.z!=0.0)
        lambda1 = (vb.x*d.z - d.x*vb.z)/(va.x*vb.z - vb.x*va.z);
    else if (va.y*vb.z - vb.y*va.z!=0.0)
        lambda1 = (vb.y*d.z - d.y*vb.z)/(va.y*vb.z - vb.y*va.z);
    if (vb.x*va.y - va.x*vb.y!=0.0)
        lambda2 = (d.x*va.y - va.x*d.y)/(vb.x*va.y - va.x*vb.y);
    else if (vb.x*va.z - va.x*vb.z!=0.0)
        lambda2 = (d.x*va.z - va.x*d.z)/(vb.x*va.z - va.x*vb.z);
    else if (vb.y*va.z - va.y*vb.z!=0.0)
        lambda2 = (d.y*va.z - va.y*d.z)/(vb.y*va.z - va.y*vb.z);
    if (lambda1<0 || lambda1 >1 || lambda2<0 || lambda2 >1)
        return LLINF;
    else return abs(proj(b1-a1, cross(va, vb)));
}


ld ver(vector<point> a, vector<point> b){
    ld ans = LLINF;
    // vertex-vertex
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            ans = min(ans, dist(a[i], b[j]));

    // edge-edge
    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
            for(int m=0;m<4;m++)
                for(int p=m+1;p<4;p++)
                    ans = min(ans, distRetaReta(a[i], a[j], b[m], b[p]));

    // vertex-edge
    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
            for(int k=0;k<4;k++)
                ans = min(ans, distPontoReta(a[k], b[i], b[j]));

    // edge-vertex
    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
            for(int k=0;k<4;k++)
                ans = min(ans, distPontoReta(b[k], a[i], a[j]));


    // vertex-face
    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
            for(int k=j+1;k<4;k++)
                for(int m=0;m<4;m++)
                    ans = min(ans, distPontoPlano(a[m], b[i], b[j], b[k]));

    // face-vertex
    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
            for(int k=j+1;k<4;k++)
                for(int m=0;m<4;m++)
                    ans = min(ans, distPontoPlano(b[m], a[i], a[j], a[k]));
    return ans;
}