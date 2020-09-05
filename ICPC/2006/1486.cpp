#include <bits/stdc++.h>
#define f0(n) for(int i = (int)0; i < (int)n; i++)
#define f1(a, b) for(int i = (int)a; i < (int)b; i++)
#define f2(i, n) for(int i = 0; i < (int)n; i++)
#define f3(i, a, b) for(int i=(int)a;i<(int)b;i++)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define MAX 1010
using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

int m[MAX][MAX];

int main()
{
   
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, p, c;
    while(cin >> p >> n >> c){
        if(p == 0 && n == 0 && c == 0) break;

        f2(i, n){
            f2(j, p){
                cin >> m[i][j];
            }
        }
        
        int ans = 0;

        f2(i, p){
            f2(j, n){
                if(m[j][i] == 1){
                    int k = j;
                    int cnt = 0;
                    while(m[k][i] == 1 && k < n){
                        cnt++;
                        k++;
                    }
                    j = k;
                    if(cnt >= c) ans++;
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}
 