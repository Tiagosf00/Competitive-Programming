int N;

int sum(int i, int x){
    if(i+x>N-1) return (i+x-N);
    return i+x;
}

ld rotating_callipers(vp &vet){
    N = vet.size();
    ld ans = 0;
    // 2 triangulos (p1, p3, p4) (p1, p2, p3);
    for(int i=0;i<N;i++){ // p1
        int p2 = sum(i, 1); // p2
        int p4 = sum(i, 3); // p4
        for(int j=sum(i, 2);j!=i;j=sum(j, 1)){ // p3
            if(j==p2) p2 = sum(p2, 1);
            while(sum(p2, 1)!=j and areaT(vet[p2], vet[i], vet[j]) < areaT(vet[sum(p2, 1)], vet[i], vet[j]))
                p2 = sum(p2, 1);
            while(sum(p4, 1)!=i and areaT(vet[p4], vet[i], vet[j]) < areaT(vet[sum(p4, 1)], vet[i], vet[j]))
                p4 = sum(p4, 1);

            ans = max(ans, area(vet[i], vet[p2], vet[j], vet[p4]));
        }
    }

    return ans;
}