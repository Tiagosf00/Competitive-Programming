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
		vi zrs;
		int post[n];
		REP(i, 0, n) cin >> post[i];
		int counter = 0;
		REP(i, 0, n){
			if(post[i] == 0)
				counter++;
			else
			{
				if(counter!=0)
					zrs.pb(counter);
				counter = 0;
			}
		}
		if(post[0] == 0 && zrs.size() > 0){
			zrs[0] += counter;
		}else if(counter > 0){
			if(post[0] == 0){
				counter++;
			}
			zrs.pb(counter);
		}
		int res = 0;
		REP(i, 0, zrs.size()){
			res += zrs[i]/2;
		}
		cout << res << endl;
	}

    return 0;
}