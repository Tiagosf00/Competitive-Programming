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

	int a[3], m[3];
	cin >> a[0] >> a[1] >> a[2];

	m[0] = a[0]*4 + a[1]*2;
	m[1] = a[0]*2 + a[2]*2;
	m[2] = a[1]*2 + a[2]*4;

	if(m[0] <= m[1] && m[0] <= m[2])
		cout << m[0] << endl;
	else if(m[1] <= m[0] && m[1] <= m[2])
		cout << m[1] << endl;
	else if(m[2] <= m[0] && m[2] <= m[1])
		cout << m[2] << endl;

	return 0;
}