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

typedef struct pl{
	int p;
	vi r;
}pl;

bool compare(const pl& a, const pl& b){
	return a.r.size() > b.r.size();
}

int main()
{
	
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n, m;
	while(cin >> n >> m && (n || m)){
		map<int, vi> x;
		rep1(i, n){
			rep1(j, m){
				int num; cin >> num;
				if(x.find(num) == x.end()){
					x.insert({num, {j+1}});
				}else{
					x[num].pb(j+1);
				}
			}
		}
		pl rank[x.size()];
		int i = 0;
		for(map<int, vi>::iterator it = x.begin();it!=x.end();it++){
			rank[i].p = it->first;
			rep1(j, it->second.size()){
				rank[i].r.pb(it->nd[j]);
			}
			i++;
		}
		rep1(i, x.size()){
			sort(rank[i].r.begin(), rank[i].r.end());
		}
		sort(rank, rank + x.size(), compare);
		vector<int> ans;
		rep1(i, x.size()){
			if(rank[i].r.size() == rank[1].r.size()){
				ans.pb(rank[i].p);
			}
		}
		sort(ans.begin(), ans.end());
		rep1(i, ans.size()){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}