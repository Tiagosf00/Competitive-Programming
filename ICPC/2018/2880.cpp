#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, b) for(int i=(int)a;i<(int)b;i++)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long int
#define MAX 100010
#define oo INT_MAX
using namespace std;

int main(){

	fastio;

	string msg, cri;
	cin >> msg >> cri;
	int ans = 0;
	rep(i, 0, msg.size()){
		if(i+cri.size() == msg.size()+1)
			break;
		bool has = false;
		int k = i;
		rep(j, 0, cri.size()){
			if(has) break;
			if(cri[j] == msg[k])
				has = true;
			k++;
		}
		if(!has) ans++;
	}
	cout << ans << endl;
}