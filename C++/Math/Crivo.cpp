// Sieve of Eratosthenes

vi p(MAX, true);

for(ll i=4; i<MAX; i++) p[i] = 2;
for(ll i=3; i<MAX; i+=2)
    if(!p[i])
        for(ll j=i*i; j<MAX; j+=2*i)
            p[j] = i;
