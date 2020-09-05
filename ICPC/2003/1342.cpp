#include <bits/stdc++.h>
using namespace std;

int trap[3];

bool fell(int key){
	for(int i=0;i<3;i++){
		if(key == trap[i])
			return true;
	}
	return false;
}

int main()
{

	int p, s;
	while(cin >> p >> s && (p != 0 && s != 0)){
		cin >> trap[0] >> trap[1] >> trap[2];
		vector<bool> v(p+1, false);
		vector<int> stp(p+1, 0);
		int turn = 1, n;
		vector<pair<int, int>> vp;
		cin >> n;
		for(int i=0;i<n;i++){
			int x, y;
			cin >> x >> y;
			vp.push_back(make_pair(x, y));
		}
		int index = 0;
		while(index < n){
			if(!v[turn]){
				int sum = vp[index].first + vp[index].second;
				index++;
				stp[turn] += sum;
				if(stp[turn] > s){
					cout << turn << '\n';
					break;
				}
				if(fell(stp[turn])){
					v[turn] = true;
				}
				turn++;
				if(turn == p+1){
					turn = 1;
				}
			}else{
				v[turn] = false;
				turn++;
				if(turn == p+1)
					turn = 1;
			}
		}
	}

	return 0;
}
