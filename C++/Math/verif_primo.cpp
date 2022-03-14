// Prime verification sqrt(N)
		
bool prime(ll x){
	if(x==2) return true;
	else if(x==1 or x%2==0) return false;
	for(ll i=3;i*i<=x;i+=2)
		if(x%i==0)
			return false;
	return true;
}
