ld gcdf(ld a, ld b){
    if(a<b) return gcdf(b, a);
  
    if(fabs(b)<EPS)
        return a;
    else
        return (gcdf(b, a - floor(a/b)*b));
}