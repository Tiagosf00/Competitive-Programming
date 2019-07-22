// Crivo de Eratóstenes

int N;
vector<bool> primos(100010, true);
cin >> N;

primos[0]=false;
primos[1]=false;

for(int i=2;i<=N;i++)
	if(primos[i])
		for(int j=i+i; j<=N; j+=i)
			primos[j]=false;