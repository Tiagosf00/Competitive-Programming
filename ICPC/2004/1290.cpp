//defines e includes
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep1(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, a, b) for(int i=(int)a;i<(int)b;i++)
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define p_b pop_back
#define p_f pop_front
#define mp make_pair
#define MAX 100010
#define oo INT_MAX
using namespace std;
//tipagem de pares
typedef pair<int, int> ii;
typedef pair<char, char> cc;
typedef pair<int, char> ic;
typedef pair<char, int> ci;
//tipagem de vetores
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef vector<bool> vb;
//tipagem de outras estruturas
typedef queue<int> qi;
typedef deque<int> dqi;
//tipagem de tipos primitivos
typedef long long int ll;
typedef unsigned long long int ull;

string to_str(int x, int y, int z){
	int v[3] = {x, y, z};
	sort(v, v+3);
	string a = "";
	for(int i=2;i>=0;i--){
		while(v[i] > 0){	
			a.pb(v[i]%10 + '0');
			v[i]/=10;
		}
		a.pb(' ');
	}
	string b;
	for(int i=a.size()-1;i>=0;i--){
		b.pb(a[i]);
	}
	return b;
}

int main()
{
	
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n, m;
	while(cin >> n >> m && (n || m)){

		int v[3];
		cin >> v[0] >> v[1] >> v[2];
		sort(v, v+3);
		int gv = v[0]*v[1]*v[2];
		vvi v2(m);
		rep1(i, m){
			int x, y, z;
			cin >> x >> y >> z;
			if(x*y*z - gv >= 0){
				v2[i].pb(x);
				v2[i].pb(y);
				v2[i].pb(z);
				sort(v2[i].begin(), v2[i].end());
			}
		}
		bool exact = false;
		int ans = oo;
		rep1(i, m) if(v2[i].size() != 0){
			int gv2 = v2[i][0]*v2[i][1]*v2[i][2];
			if(v2[i][0] >= v[0] && v2[i][1] >= v[1] && v2[i][2] >= v[2] &&
				gv2 >= gv){
				int count = 1;
				rep1(j, m)if(j != i && v2[j].size() != 0){
					if(v2[j][0] == v2[i][0] && v2[j][1] == v2[i][1] && v2[j][2] == v2[i][2]){
						count++;
						if(count >= n){
							break;
						}
					}
				}
				if(count >= n){
					ans = min(ans, gv2 - gv);
					exact = true;
				}
			}
		}
		if(exact){
			cout << ans << endl;
		}else{
			cout << "impossible" << endl;
		}

	}

	return 0;
}