// Sieve of Eratosthenes

vector<bool> primos(MAX, true);

primos[0]=primos[1]=false;

for(int i=2;i<MAX;i++)
    if(primos[i])
        for(int j=i+i; j<MAX; j+=i)
            primos[j]=false;
