// Modular exponentiaion - (x^y)%p in O(log y)
int power(int x, unsigned int y, int p) 
{
    int res = 1;
    x%=p;

    while(y>0)
    { 
        if(y&1)
            res=(res*x)%p;
  
        y=y>>1;
        x=(x*x)%p;
    }
}