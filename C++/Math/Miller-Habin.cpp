ll llrand()
{
	ll tmp = rand();
	return (tmp << 31) | rand();
}
 
ll add(ll a, ll b, ll c)
{
	return (a + b)%c;
}
 
ll mul(ll a, ll b, ll c)
{
	ll ans = 0;
	while(b)
	{
		if(b & 1)
			ans = add(ans, a, c);
		a = add(a, a, c);
		b /= 2;
	}
	return ans;
}
 
ll fexp(ll a, ll b, ll c)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1)
			ans = mul(ans, a, c);
		a = mul(a, a, c);
		b /= 2;
	}
	return ans;
}
 
bool rabin(ll n)
{
	if(n <= 1)
		return 1;
	if(n <= 3)
		return 1;
 
	ll s=0, d=n-1;
	while(d%2==0)
	{
		d/=2;
		s++;
	}
 
	for(int k = 0; k < 64*4; k++)
	{
		ll a = (llrand()%(n - 3)) + 2;
		ll x = fexp(a, d, n);
		if(x != 1 and x != n-1)
		{
			for(int r = 1; r < s; r++)
			{
				x = mul(x, x, n);
				if(x == 1)
					return 0;
				if(x == n-1)
					break;
			}
			if(x != n-1)
				return 0;
		}
	}
 
	return 1;
}
 
 
int main()
{

	ll N;
	cin >> N;
 
	cout << rabin(N) << endl;
 
	return 0;
 
}