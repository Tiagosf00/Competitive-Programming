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
#define ull unsigned long long int
#define MAX 310
#define MOD 1000000007
#define oo 0x7fffffff
#define endl '\n'
using namespace std;

ll a, b;

ll count(ll x){
	ll ans = 0;
	ll t = x;
	ll d = 1LL;
	while(t > 0){
		ans += (x/(d*2))*1LL*(d);
		if(x%(d*2) > (d)) ans += (x%(d*2)) - (d);
		t /= 2;
		d *= 2;
	}
	return ans;
}

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	while(cin >> a >> b){
		b++;
		ll cb = count(b);
		ll ca = count(a);
		ll res = cb - ca;
		cout << res << endl;
	}


    return 0;
}