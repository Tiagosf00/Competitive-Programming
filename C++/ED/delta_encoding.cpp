// Delta encoding

for(int i=0;i<q;i++){
    int l,r,x;
    cin >> l >> r >> x;
    delta[l] += x;
    delta[r+1] -= x;
}

int atual = 0;
	
for(int i=0;i<n;i++){
    atual += delta[i];
    v[i] += atual;
}
