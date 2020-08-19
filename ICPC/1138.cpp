#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define MAX 100010
#define MOD 1000000007
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int ll;

int nine[9] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

int stoint(string s){
	int ans=0, d = 1;
	// cout <<s << endl;
	for(int i=s.size()-1;i>=0;i--){
		ans += (s[i]-'0')*d;
		d*=10;
	}
	return ans;
}

void count(vi & V, string s, size_t t){
	int pd = pow(10, t-1);
	REP(i, 0, 10){
		if(i == 0){
			int tmp = t;
			while(tmp > 1){
				int p = pow(10, tmp-1);
				V[i] -= p;
				tmp--;
			}
		}
		V[i] += t*pd;
	}
	int d = 10;
	int f = t-1;
	REP(i, 0, t-1){
		int sub = 9 - (s[i]-'0');
		sub = sub*(pd/d)*f;
		REP(j, 0, 10) V[j] -= sub;
		f--;
		d*=10;
	}
	// cout << s.substr(1, 1) << endl;
	REP(i, 0, 10){
		f = t-1;
		REP(j, 0, t){
			if(i > (s[j]-'0')){
				V[i] -= pow(10, f);
			}else if(i == (s[j]-'0')){
				if(j < (int)(t-1)){
					V[i] -= (nine[f-1]-stoint(s.substr(j+1, f)));
					// cout << j+1 << " " << f-1 << endl;
				}
			}
			f--;
		}
	}
}

void solve(string a, string b){
	vi ans(10, 0);
	vi A(10, 0);
	vi B(10, 0);
	count(A, a, a.size());
	count(B, b, b.size());
	REP(i, 0, a.size()){
		ans[a[i]-'0']++;
	}
	REP(i, 0, 10){
		ans[i] += (B[i] - A[i]);
		cout << ans[i] << (i == 9 ? "\n": " ");
	}
}

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int a, b;
	while(cin >> a >> b && !(a == 0 && b == 0)){
		solve(to_string(a), to_string(b));
	}


    return 0;
}