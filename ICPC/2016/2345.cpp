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

int main()
{
	
	fastio;
	
	int v[4];
	int ans = oo;
	cin >> v[0] >> v[1] >> v[2] >> v[3];
	sort(v, v+4);
	do{
		int diff = abs((v[0]+v[1]) - (v[2]+v[3]));
		if(diff < ans)
			ans = diff;
	}while(next_permutation(v, v+4));

	cout << ans << endl;

	return 0;
}