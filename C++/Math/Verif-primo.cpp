// prime verification sqrt(N)
		
bool eh_primo(long long N)
{
	if(N==2)
		return true;
	else if(N==1 or N%2==0)
		return false;
	for(long long i=3;i*i<=N;i+=2)
		if(N%i==0)
			return false;
	return true;
}
