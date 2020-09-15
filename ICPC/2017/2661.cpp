#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define vi vector<int>
#define ii pair<int, int>
#define ll long long int
#define MAX 200010
#define MOD 1000000007
#define oo 0x7fffffff
#define endl '\n'
using namespace std;

bool isprime(ll n){
	if(n < 2)
		return false;
	REP(i, 2, sqrt(n))
		if(n%i == 0)
			return false;
	return true;
}

int main()
{

	ll n;
	cin >> n;

	if(isprime(n)){
		cout << 0 << endl;
	}else{
		ll c = 0, p = 2, k = sqrt(n);
		while(n > 1 && p <= k){
			if(n%p == 0){
				c++;
				while(n%p == 0)
					n/=p;
			}
			p++;
		}

		if(n > 1)
			c++;

		ll ans = pow(2, c) - c - 1;
		cout << ans << endl;
	}

	return 0;
}