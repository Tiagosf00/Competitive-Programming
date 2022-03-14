// Newton Raphson

ld f(x){ return x*2 + 2; }
ld fd(x){ return 2; } // derivada

ld root(ld x){
    // while(f(x)>EPS)
    for(int i=0;i<20;i++){
        if(fd(x)<EPS)
            x = LLINF;
        else
            x = x - f(x)/fd(x);
    }
    return x;
}