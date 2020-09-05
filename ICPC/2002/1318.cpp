#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, a, b) for(i=(int)a;i<(int)b;i++)
#define MAX 100010

typedef struct pair{
	int st, nd;
}pair;

int compare(const void * a, const void * b){
	return (*(pair*)b).st - (*(pair*)a).st;
}

int main()
{

	int n, m, i;
	while(scanf("%d%d", &n, &m) && (n != 0 && m != 0)){
		int * counter = (int*)calloc(MAX, sizeof(int));
		rep(i, 0, m){
			int x;
			scanf("%d", &x);
			counter[x]++;
		}
		int fake = 0;
		rep(i, 1, n+1){
			if(counter[i] > 1) fake++;
		}
		printf("%d\n", fake);
	}
	

	return 0;