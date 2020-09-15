#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long int lli;


int main()
{

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, x;
	cin >> n >> x;
	int v[n];
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	sort(v, v+n);
	int ans = 1;
	for(int i=n-1;i>=1;i--){
		int pos = 1;
		for(int j=i;j>=1;j--){
			if(v[j] - v[j-1] <= x){
				pos++;
			}else{
				break;
			}
		}
		ans = max(ans, pos);
	}
	cout << ans << endl;

	return 0;
}