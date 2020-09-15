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

	int c, b, f;
	int x, y, z;
	cin >> c >> b >> f;
	cin >> x >> y >> z;

	int no = 0;
	if(x > c){
		no += (x-c);
	}

	if(y > b){
		no += (y-b);
	}

	if(z > f){
		no += (z-f);
	}

	cout << no << endl;

	return 0;
}