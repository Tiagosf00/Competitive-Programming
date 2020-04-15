int l=1, r=N;
int res=-1;

while(l<=r){
    int m = (l+r)/2;
    if(!ver(m)){
    	l = m+1;
    }
    else{
    	res = m;
    	r = m-1;
    }
}
cout << res << endl;
