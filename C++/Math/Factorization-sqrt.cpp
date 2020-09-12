// Factorization of a number in sqrt(n)

vi fact(ll n){
    vector<int> div;
    for(ll i=2;i*i<=n;i++)
        if(n%i==0){
            div.pb(i);
            while(n%i==0)
                n/=i;
        }
    if(n!=1) div.pb(n);
    return div;
}