ld heron(int a, int b, int c){
    ld s = (a+b+c)/2.0;
    return sqrtl(s*(s-a)*(s-b)*(s-c));
}

ld heron(int a, int b, int c, int d){
    ld s = (a+b+c+d)/2.0;
    return sqrtl((s-a)*(s-b)*(s-c)*(s-d));
}