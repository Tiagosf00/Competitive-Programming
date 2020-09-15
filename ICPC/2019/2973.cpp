#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

int N, C, T;
int v[MAX];

int main()
{

	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> C >> T;
	int max=-1;
	long int time = 0, acc = 0;
	for(int i=0;i<N;i++){
		cin >> v[i];
		acc += v[i];
		if(v[i] > max){
			max = v[i];
		}
		time+=(int)ceil((double)v[i]/T);
	}
	int res = 0;
	long int l = (int)ceil((double)max/T), r = time+10;
	while(l < r){
		long int mid = (r-l)/2 + l;
		int counter = 0; acc = 0;
		for(int i=0;i<N;i++){
			acc += v[i];
			if(acc > mid*T){
				acc = v[i];
				counter++;
			}
		}
		if(acc >= v[N-1]){
			counter++;
		}

		if(counter <= C){
			r = mid;
			res = mid;
		}else{
			l = mid+1;
			if(l == r){
				res = l;
			}
		}
	}

	cout << res << endl;

	return 0;
}
