bool nulo(point a){
    return (eq(a.x, 0) and eq(a.y, 0) and eq(a.z, 0));
}

ld misto(point p1, point p2, point p3){
    return (p1^p2)*p3;
}

ld dist_pt_face(point p, vp v){
    assert(v.size()==3);

    point v1 = v[1]-v[0];
    point v2 = v[2]-v[0];
    point n = (v1^v2);
    
    for(int i=0;i<3;i++){
        point va = p-v[i];
        point vb = v[(i+1)%3]-v[i];
        point ve = vb^n;
        ld d = ve*v[i];
        //se ponto coplanar com um dos lados do prisma (va^vb eh nulo),
        //ele esta dentro do prisma (poderia desconsiderar pois distancia
        //vai ser a msm da distancia do ponto ao segmento)
        if(!nulo(va^vb) and (v[(i+2)%3]*ve>d) ^ (p*ve>d)) return LLINF;
    }
    
    //se ponto for coplanar ao triangulo (e dentro do triangulo)
    //vai retornar zero corretamente
    return fabs(misto(p-v[0],v1,v2)/norm(n));
}

ld dist_pt_seg(point p, vp li){
    return norm((li[1]-li[0])^(p-li[0]))/norm(li[1]-li[0]);
}

ld dist_line(vp l1, vp l2){
    point n = (l1[1]-l1[0])^(l2[1]-l2[0]);
    if(nulo(n)) //retas paralelas - dist ponto a reta
        return dist_pt_seg(l2[0],l1);
        
    point o1o2 = l2[0]-l1[0];
    return fabs((o1o2*n)/norm(n));
}
// retas paralelas e intersecao nao nula
ld dist_seg(vp l1, vp l2){

    assert(l2.size()==2);
    assert(l1.size()==2);
    
    //pontos extremos do segmento
    ld ans = LLINF;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            ans = min(ans, norm(l1[i]-l2[j]));
    
    //verificando distancia de ponto extremo com ponto interno dos segs
    for(int t=0;t<2;t++){
        for(int i=0;i<2;i++){
            bool c=true;
            for(int k=0;k<2;k++){
                point va = l1[i]-l2[k];
                point vb = l2[!k]-l2[k];
                ld ang = atan2(norm((vb^va)), vb*va);
                if(ang>PI/2) c = false;
            }
            if(c)
                ans = min(ans,dist_pt_seg(l1[i],l2));
        }
        swap(l1,l2);
    }

    //ponto interno com ponto interno dos segmentos
    point v1 = l1[1]-l1[0], v2 = l2[1]-l2[0];
    point n = v1^v2;
    if(!nulo(n)){
        bool ok = true;
        for(int t=0;t<2;t++){
            point n2 = v2^n;
            point o1o2 = l2[0]-l1[0];
            ld escalar = (o1o2*n2)/(v1*n2);
            if(escalar<0 or escalar>1) ok = false;
            swap(l1,l2);
            swap(v1,v2);
        }
        if(ok) ans = min(ans,dist_line(l1,l2));
    }
    
    return ans;
}

ld ver(vector<vp> &vet){
    ld ans = LLINF;
    // vertice - face
    for(int k=0;k<2;k++)
        for(int pt=0;pt<4;pt++)
            for(int i=0;i<4;i++){
                vp v;
                for(int j=0;j<4;j++){
                    if(i!=j) v.pb(vet[!k][j]);
                }
                ans = min(ans, dist_pt_face(vet[k][pt], v));
            }

    // edge - edge
    for(int i1=0;i1<4;i1++)
        for(int j1=0;j1<i1;j1++)
            for(int i2=0;i2<4;i2++)
                for(int j2=0;j2<i2;j2++)
                    ans = min(ans, dist_seg({vet[0][i1], vet[0][j1]},
                                            {vet[1][i2], vet[1][j2]}));

    return ans;
}