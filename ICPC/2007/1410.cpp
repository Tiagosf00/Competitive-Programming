#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(i=(int)a;i<(int)b;i++)
#define MAX 100010
using namespace std;

int main()
{	

	fastio;
	int a, d, i;
	while(cin >> a >> d){
		if(a == 0 && d == 0) break;
		vector<int> str(a);
		vector<int> def(d);
		rep(i, 0, a)
			cin >> str[i];
		rep(i, 0, d)
			cin >> def[i];
		sort(str.begin(), str.end());
		sort(def.begin(), def.end());
		int pen = def[1];
		bool offside = false;
		rep(i, 0, a) if(str[i] <= pen){
			if(str[i] == pen)
				continue;
			else
				offside = true;
		}
		if(offside)
			cout << "Y\n";
		else
			cout << "N\n";
	}

	return 0;
}