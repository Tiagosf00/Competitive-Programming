#include <stdio.h>

int main()
{

	int n;
	while(scanf("%d", &n) && n){
		int m=0, j=0, i;
		for(i=0;i<n;i++){
			int v; scanf("%d", &v);
			if(v){
				j++;
			}else{
				m++;
			}
		}
		printf("Mary won %d times and John won %d times\n", m, j);
	}

	return 0;
}
