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

char solve(string s){
	set<char> v = {'a', 'e', 'i', 'o', 'u'};
	string a;
	REP(i, 0, s.size()){
		if(v.find(s[i]) != v.end())
			a += s[i];
	}
	string r;
	REP(i, 0, a.size()){
		r += a[i];
	}
	int t = r.size();
	REP(i, 0, t/2){
		swap(r[i], r[t-i-1]);
	}
	if(r.compare(a) == 0)
		return 'S';
	return 'N';
}

int main()
{
	
	fastio;

	string s;
	getline(cin, s);

	cout << solve(s) << endl;

	return 0;
}