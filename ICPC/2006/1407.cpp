#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(i=(int)a;i<(int)b;i++)
#define MAX 100010
using namespace std;

int main()
{	

	fastio;
	int n, c, k;
	while(cin >> n >> c >> k){
		if(n == 0 && c == 0 && k == 0) break;
		int count[MAX] = {0};
		for(int j=0;j<n;j++){
			for(int i=0;i<c;i++){
				int x; cin >> x;
				count[x]++;
			}			
		}
		vector<pair<int, int>> canum;
		for(int i=1;i<=k;i++){
			canum.push_back(make_pair(count[i], i));
		}
		sort(canum.begin(), canum.end());
		vector<int> ans;
		for(int i=0;i<(int)canum.size();i++){
			if(canum[i].first == canum[0].first)
				ans.push_back(canum[i].second);
		}
		for(size_t i=0;i<ans.size();i++){
			if(i == ans.size()-1){
				cout << ans[i] << '\n';
			}else{
				cout << ans[i] << ' ';
			}
		}
	}

	return 0;
}