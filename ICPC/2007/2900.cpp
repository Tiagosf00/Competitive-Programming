//defines e includes
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, n) for(i=int(a);i<int(n);i++)
#define rep2(i, a, n, jump) for(i=int(a);i<int(n);i+=int(jump))
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define p_b pop_back
#define p_f pop_front
#define mp make_pair
#define MAX 10010
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

int main()
{
	
	fastio;
	int n;
	while(cin >> n && n){
		int q = 0;
		while(n--){
			int ci, vi;
			cin >> ci >> vi;
			if(vi >= 2){
				q += vi/2;
			}			
		}
		cout << q/2 << '\n';
	}
	cout << '\n';

	return 0;
}