#include <bits/stdc++.h>
using namespace std;

bool compare(const int a, const int b){
	return a > b;
}

int main()
{

	int n;
	while(cin >> n && n){
		vector<int> var;
		for(int i=0;i<n;i++){
			int c, v;
			cin >> c >> v;
			if(v >= 2 && v%2 == 0){
				var.push_back(v);
			}else if(v > 2){
				v--;
				var.push_back(v);
			}
		}

		int rect=0;
		int sz = var.size();
		sort(var.begin(), var.end(), compare);
		for(int i=0;i<sz;i++){
			for(int j=0;j<sz;j++){
				if(i!=j){
					int m = min(var[i], var[j]);
					rect+=(m/2);
					var[i]-=m;
					var[j]-=m;
				}
			}
		}
		for(int i=0;i<sz;i++){
			rect+=(var[i]/4);
		}
		cout << rect << endl;


	}

	return 0;
}