#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
#define ll long long int
#define MAX 200010
#define MOD 1e9+7
#define oo INT_MAX
#define endl '\n'
using namespace std;

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int v[n];

	REP(i, 0, n){
		cin >> v[i];
	}

	int esq[n], dir[n];
	esq[0] = 1;
	dir[n-1] = 1;

	int i = 0, j = n-1;
	int ans = 1;
	while(i < n-1){
		esq[i+1] = min(esq[i]+1, v[i+1]);
		dir[j-1] = min(dir[j]+1, v[j-1]);
		j--;
		i++;
	}
	
	REP(i, 0, n){
		ans = max(ans, min(esq[i], dir[i]));
	}

	cout << ans << endl;

    return 0;
}