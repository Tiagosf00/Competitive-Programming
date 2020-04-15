struct node{
    int val;
    int l, r;
    node(int a=-1, int b=-1, int c=0){
        val=c;l=a;r=b;
    }
};

node tree[8600010]; // 4*nlog(4*n) space = 8600010
int idx=0;

int build(int l, int r){
    if(l==r)
        return idx++;

    int mid = (l+r)/2;

    tree[idx].l = build(l, mid);
    tree[idx].r = build(mid+1, r);

    return idx++;
}
 
int update(int l, int r, int root, int e){
    if(l>e or r<e)
        return root;
    if(l==e and r==e){
        tree[idx]=node(-1, -1, tree[root].val+1);
        return idx++;
    }
    int mid = (l+r)/2;
    tree[idx]=node(update(l, mid, tree[root].l, e), 
                   update(mid+1, r, tree[root].r, e), tree[root].val+1);
    return idx++;
}
 
int query(int l, int r, int root1, int root2, int k){
    while(l!=r)
    {
        int mid=(l+r)/2;
        if(tree[tree[root2].l].val-tree[tree[root1].l].val>=k)
        {
            r = mid;
            root1 = tree[root1].l;
            root2 = tree[root2].l;
        }else
        {
            l = mid+1;
            k-=tree[tree[root2].l].val-tree[tree[root1].l].val;
            root1 = tree[root1].r;
            root2 = tree[root2].r;
        }
    }
    return l;
}


int main()
{sws;

    int n, m, a, b, k;
    int v[MAX], aux[MAX];
    int root[MAX];

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> v[i]; aux[i]=v[i];
    }

    sort(v, v+n);

    map<int, int> comp;
    for(int i=0, j=0;i<n;i++)
        if(i==0 or v[i]!=v[i-1])
            comp[v[i]]=j++;
    
    root[0]=build(0, n-1);

    for(int i=1;i<=n;i++)
        root[i] = update(0, n-1, root[i-1], comp[aux[i-1]]);

    for(int i=0;i<m;i++){
        cin >> a >> b >> k;
        cout << v[query(0, n-1, root[a-1], root[b], k)] << endl;
    }

    return 0;
}
