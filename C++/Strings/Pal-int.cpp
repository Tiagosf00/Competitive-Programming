bool ehpalindromo(ll n) 
{
    if(n<0)
        return false;

    int divisor = 1; 
    while(n/divisor >= 10) 
        divisor *= 10; 
  
    while(n != 0) 
    { 
        int leading = n / divisor;
        int trailing = n % 10;

        if(leading != trailing)
            return false; 

        n = (n % divisor)/10; 
  
        divisor = divisor/100; 
    }

    return true; 
}