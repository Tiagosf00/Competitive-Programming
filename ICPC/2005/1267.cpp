#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int mtx[510][110];

int main()
{

	fastio;
	int n, d;
	while(cin >> n >> d && (n || d)){
		for(int i=0;i<d;i++){
			for(int j=0;j<n;j++){
				cin >> mtx[i][j];
			}
		}

		bool has = false;

		for(int i=0;i<n && !has;i++){
			int j;
			for(j=0;j<d;j++){
				if(!mtx[j][i]){
					break;
				}
			}
			if(j == d){
				has = true;
			}
		}

		if(has){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}



	return 0;
}