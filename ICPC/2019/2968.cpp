#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int uli;

int main()
{
	uli v, n;
	cin >> v >> n;
	for(uli i=1;i<=9;i++){
		uli tot = v*n;
		tot*=i;
		if(tot%10 == 0){
			cout << tot/10;
		}else{
			uli x = tot/10;
			x++;
			cout << x;
		}

		cout << (i == 9 ? '\n' : ' ');
		
	}

	return 0;
}
