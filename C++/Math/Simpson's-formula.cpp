const int N = 1e6;

ld simpson_integration(ld a, ld b)
{
    ld h = (b - a) / N;
    ld s = f(a) + f(b); // a = x_0 and b = x_2n
    for(int i=1;i<N;i++){ // Final Simpson's formula
        ld x = a + h*i;
        s += f(x)*((i & 1) ? 4 : 2);
    }
    s*=h/3;
    return s;
}