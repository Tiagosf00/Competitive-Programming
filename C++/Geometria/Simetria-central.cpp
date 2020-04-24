c = center(a);
if(n&1)
	cout << "NO\n";
for(int i=0;i<n/2;i++) //ordered
    if(!collinear(a[i], a[i+n/2], c))
        cout << "NO\n";
