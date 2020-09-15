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

int v[MAX];
int n, k;

int main()
{

	fastio;

	cin >> n >> k;
	REP(i, 0, n){
		cin >> v[i];
	}

	sort(v, v+n);

	int cl = 0;
	int i = n-1;

	while(i >= 0){
		if(cl < k){
			cl++;
			i--;
		}else{
			int ref = i+1;
			if(v[i] == v[ref]){
				while(i >= 0 && v[i] == v[ref]){
					cl++;
					i--;
				}
			}
			break;
		}
	}

	cout << cl << endl;

	return 0;
}