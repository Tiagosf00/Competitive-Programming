// C++ program to comput n! % p using Wilson's Theorem 
#include <bits/stdc++.h> 
using namespace std; 

int power(int x, unsigned int y, int p) 
{ 
    int res = 1;
    x = x % p;

    while(y > 0)
    { 
        if(y & 1) 
            res = (res * x) % p; 
  
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
}

int modInverse(int a, int p) 
{ 
    return power(a, p-2, p); 
}

int modFact(int n, int p) 
{ 
    if (p <= n) 
        return 0; 
  
    int res = (p - 1); 
  
    for(int i = n + 1; i < p; i++) 
        res = (res * modInverse(i, p)) % p; 
    return res; 
} 
  
int main() 
{ 
    int n = 25, p = 29; 
    cout << modFact(n, p); 
    return 0; 
} 