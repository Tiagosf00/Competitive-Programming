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

char change(char ini, char mov){
	if(ini == 'N'){
		if(mov == 'D'){
			return 'L';
		}
		return 'O';
	}else if(ini == 'S'){
		if(mov == 'D'){
			return 'O';
		}
		return 'L';
	}else if(ini == 'L'){
		if(mov == 'D'){
			return 'S';
		}
		return 'N';
	}
	if(mov == 'D'){
		return 'N';
	}
	return 'S';
}

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	while(cin >> n && n){
		string mov;
		cin >> mov;
		char ini = 'N';
		REP(i, 0, n){
			ini = change(ini, mov[i]);
		}
		cout << ini << endl;
	}

    return 0;
}