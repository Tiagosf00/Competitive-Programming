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

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m;
	while(cin >> n >> m && (n || m)){
		string emoticons[n];
		string str[m];
		int c = 0;
		REP(i, 0, n){
			cin >> emoticons[i];
		}
		cin.ignore(1);
		REP(i, 0, m){
			getline(cin, str[i]);
		}
		int retire = 0, k;
		while(c < m){
			REP(i, 0, str[c].size()){
				REP(j, 0, n){
					int currSize = emoticons[j].size();
					char ch = emoticons[j][currSize-1];
					// cout << ch << endl;
					if(str[c][i] == ch){
						if(i >= currSize-1){
							int confere = 0, index = 0;
							k = i - (currSize-1);
							while(index < currSize){
								if(emoticons[j][index] == str[c][k]){
									confere++;
								}
								k++;
								index++;
							}

							if(confere == currSize){
								str[c][i] = ' ';
								retire++;
								break;
							}
						}
					}
				}
			}
			c++;
		}
		cout << retire << endl;
	}

    return 0;
}