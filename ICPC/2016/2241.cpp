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
#define MAX 510
#define MOD 1000000007
#define oo 0x7fffffff
#define endl '\n'
using namespace std;

int m[MAX][MAX];

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, p;

	cin >> n >> p;

	REP(i, 0, n+1)
		REP(j, 0, n+1)
			m[i][j] = 0;


	REP(i, 0, p){
		int x, y;
		cin >> x >> y;
		m[x-1][y-1] = 1;
	}

	REP(i, 0, p){
		int x, y;
		cin >> x >> y;
		m[x-1][y-1] = 2;
	}

	int b = 0, w = 0;
	for(int i=0;i<n;i++){
		int m2[n][n];
		for(int j=i+1;j<n;j++){
			for(int k=i+1;k<n;k++){
				int v[4] = {0};
				v[m[j-1][k]]++;
				v[m[j-1][k-1]]++;
				v[m[j][k-1]]++;
				v[m[j][k]]++;
				m2[j][k] = 0;
				if(v[3] == 0){
					if(v[1] > 0 && v[2] == 0){
						m2[j][k] = 1;
						b++;
					}else if(v[1] == 0 && v[2] > 0){
						m2[j][k] = 2;
						w++;
					}else if(v[1] > 0 && v[2] > 0){
						m2[j][k] = 3;
					}
				}else{
					m2[j][k] = 3;
				}
			}
		}
		for(int j=i+1;j<n;j++){
			for(int k=i+1;k<n;k++){
				m[j][k] = m2[j][k];
			}
		}
	}

	cout << b+p << " " << w+p << endl;

    return 0;
}