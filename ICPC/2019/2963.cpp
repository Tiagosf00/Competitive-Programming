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

bool compare(ii a, ii b){
    if(a.nd == b.nd)
        return a.st < b.st;
    return a.nd > b.nd;
}

int main()
{
    
	int n, i;
	cin >> n;
	ii vt[n];
	for(i=0;i<n;i++){
        int v;
        cin >> v;
		vt[i] = mp(i, v);
	}

	sort(vt, vt+n, compare);

	if(vt[0].st == 0){
		cout << "S\n";
	}else{
		cout << "N\n";
	}

	return 0;
}