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
	if(n % 2 == 0)
		return 2;
 
	ll d, c = llrand() % n, x = llrand() % n, y = x;
	do
	{
		x = add(mul(x, x, n), c, n);
		y = add(mul(y, y, n), c, n);
		y = add(mul(y, y, n), c, n);
		d = __gcd(abs(x - y), n);
	}while(d == 1);
 
	return d;
}

int main()
{
	srand(time(0));

	ll N;
	cin >> N;

	ll div = rho(N);
	cout << div << " " << N/div << endl;

	return 0;

}