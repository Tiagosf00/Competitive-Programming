// Pollard Rho Algorithm

#include <bits/stdc++.h>
#define ll long long

using namespace std;

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

ll rho(ll n)
{
	ll x, c, y, d, k;
	int i;
	do{
		i = 1;
		x = llrand()%n;
		c = llrand()%n;
		y = x, k = 4;
		do{
			if(++i == k)
			{
				y = x;
				k *= 2;
			}
			x = add(mul(x, x, n), c, n);
			d = __gcd(abs(x - y), n);
		}
		while(d == 1);
	}
	while(d == n);
	
	return d;
}

int main()
{
	srand(time(0));

	ll N;
	cin >> N;

	ll div = rho(N);
	cout << div << " " << N/div << endl;


	// Finding all divisors

	vector<ll> div;

	while(N>1 and !rabin(N))
	{
		ll d = rho(N);
		if(!rabin(d))
			continue;
		div.pb(d);
		while(N%d==0)
			N/=d;
	}
	if(N!=resp and N!=1)
		div.pb(N);

	return 0;

}