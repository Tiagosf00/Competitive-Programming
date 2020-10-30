// Sieve of Eratosthenes

vector<bool> primos(n, true);

primos[0]=primos[1]=false;

for(int i=2;i<=n;i++)
    if(primos[i])
        for(int j=i+i; j<=n; j+=i)
            primos[j]=false;
