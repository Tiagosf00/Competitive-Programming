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

int a, b, c, d;

bool verify(int i){
	if(i%b != 0 && d%i != 0 && i%a == 0){
		return true;
	}
	return false;
}

int main()
{
	
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> a >> b >> c >> d;

	int n = c;
	int ans = oo;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i == 0){
			if(n/i == i){
				if(verify(i))
					ans = min(ans, i);
			}else{
				if(verify(i))
					ans = min(ans, i);
				if(verify(n/i))
					ans = min(ans, n/i);
			}
		}
	}
	cout << (ans == oo ? -1 : ans) << endl;

	return 0;
}