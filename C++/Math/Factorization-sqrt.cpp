// Factorization of a number in sqrt(n)

int main()
{
	ll N;
	vector<int> div;

	cin >> N;

	for(ll i=2;i*i<=N;i++)
	{
		if(N%i==0)
		{
			vet.pb(i);
			while(N%i==0)
				N/=i;
		}
	}
	if(N!=1)
		vet.pb(N);

	return 0;
}