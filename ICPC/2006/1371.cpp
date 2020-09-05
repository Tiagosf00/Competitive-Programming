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
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	while(cin >> n && n){
		vi ans;
		int last = 1;
		int add = 3;
		ans.pb(last);
		REP(i, 2, n+1){
			if(i == last+add){
				ans.pb(last+add);
				last = last+add;
				add+=2;
			}
		}
		REP(i, 0, ans.size()){
			cout << ans[i] << (i == (int)ans.size()-1 ? "\n" : " ");
		}
	}

    return 0;
}