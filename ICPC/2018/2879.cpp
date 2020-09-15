#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n;
	cin >> n;
	int res = 0;
	while(n--){
	  int p; cin >> p;
	  if(p != 1){
	    res++;
	  }
	}
	cout << res << endl;

	return 0;
}
