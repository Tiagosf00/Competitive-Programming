#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(int i=int(a);i<int(b);i++)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define MAX 100010
using namespace std;

typedef vector<int> vi;
typedef long long int lld;

int solve(vector<stack<int>>& ps, int l, int r, bool dir){
	int ans = 0;
	size_t sizes[ps.size()] = {0};
	rep(i, l, r) sizes[i] = ps[i].size();
	if(!dir){
		for(int i=r-1;i>=l;i--){
			if(i == r-1){
				while(ps[i].size() >= ps[r].size()){
					ps[i].pop();
					ans++;
					if(ps[i].empty()) break;
				}
			}else{
				if(sizes[i+1] != ps[i+1].size()){
					while(ps[i].size() > ps[i+1].size()){
						ps[i].pop();
						ans++;
						if(ps[i].empty()) break;
					}
				}
			}
			
		}
	}else{
		for(int i=l;i<r;i++){
			if(i == l){
				while(ps[i].size() >= ps[i-1].size()){
					ps[i].pop();
					ans++;
					if(ps[i].empty()) break;
				}
			}else{
				if(sizes[i-1] != ps[i-1].size()){
					while(ps[i].size() > ps[i-1].size()){
						ps[i].pop();
						ans++;
						if(ps[i].empty()) break;
					}
				}
			}
		}
	}
	return ans;
}


int main()
{
	fastio;
	int n, p;
	while(cin >> n >> p){
		if(n == 0 && p == 0) break;
		vector<stack<int>> ps(p);
		int pos = 0;
		rep(i, 0, p){
			int q; cin >> q;
			rep(j, 0, q){
				int x; cin >> x;
				ps[i].push(x);
				if(x == 1) pos = i;
			}
		}
		int ans =0;
		while(ps[pos].top()!=1){
			ps[pos].pop();
			ans++;
		}
		int left, right;
		left = solve(ps, 0, pos, false);
		right = solve(ps, pos+1, p, true);	
		cout << min(ans+left, ans+right) << '\n';
	}

	return 0;
}