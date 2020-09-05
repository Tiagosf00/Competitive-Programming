//defines e includes
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep1(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, a, b) for(int i=(int)a;i<(int)b;i++)
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define p_b pop_back
#define p_f pop_front
#define mp make_pair
#define MAX 100010
#define oo INT_MAX
#define endl '\n'
using namespace std;
//tipagem de tipos primitivos
typedef long long int ll;
typedef unsigned long long int ull;
//tipagem de pares
typedef pair<int, int> ii;
typedef pair<char, char> cc;
typedef pair<int, char> ic;
typedef pair<char, int> ci;
typedef pair<ll, ll> llp;
//tipagem de vetores
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef vector<vector<pair<int, int>>> wadj;
typedef vector<bool> vb;
//tipagem de outras estruturas
typedef queue<int> qi;
typedef deque<int> dqi;
typedef priority_queue<ii, vector<ii>, greater<ii>> min_pq;
//classes frequentemente usadas
class Edge{public:int u, v, w;
bool operator<(const Edge& x) const {return this->w < x.w;}};

bool compare(int a, int b){ return a > b; }

int v[MAX];

int main()
{
	
	//fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t, n;
	while(cin >> t >> n && (t || n)){
		int dr = 0, vc = 3*n;
		rep1(i, t){
			string s;
			cin >> s >> v[i];
			dr += v[i];
		}
		
		cout << vc-dr << endl;
	}

	return 0;
}