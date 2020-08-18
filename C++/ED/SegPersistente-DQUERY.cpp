// distinct elements in the range [l, r]
struct node{
    int val;
    int l, r;
    node(int a=-1, int b=-1, int c=0){
        val=c;l=a;r=b;
    }
};

node tree[8600010]; // nlog(n) space = 8600010
int idx=0;

int build(int l, int r){
    if(l==r)
        return idx++;

    int mid = (l+r)/2;

    tree[idx].l = build(l, mid);
    tree[idx].r = build(mid+1, r);

    return idx++;
}
 
int update(int l, int r, int root, int e, int o){
    int plus=0;
    if((l>e or r<e) and (l>o or r<o or o==-1))
        return root;
    if(l<=e and e<=r) plus++;
    if(l<=o and o<=r and o!=-1) plus--;

    if(l==e and r==e){
        tree[idx]=node(-1, -1, 1);
        return idx++;
    }
    if(l==o and r==o){
        tree[idx]=node(-1, -1, 0);
        return idx++;
    }
    int mid = (l+r)/2;
    tree[idx]=node(update(l, mid, tree[root].l, e, o), 
                   update(mid+1, r, tree[root].r, e, o), tree[root].val+plus);
    return idx++;
}
 
int query(int a, int b, int l, int r, int root){
    if(l>b or r<a)
        return 0;
    if(l<=a and b<=r)
        return tree[root].val;
    int mid = (a+b)/2;

    return query(a, mid, l, r, tree[root].l) + query(mid+1, b, l, r, tree[root].r);
}


int main()
{sws;

    int n, m, a, b;
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

    int last[MAX];
    memset(last, -1, sizeof(last));

    for(int i=0;i<n;i++){
        root[i+1] = update(0, n-1, root[i], i, last[comp[aux[i]]]);
        last[comp[aux[i]]]=i;
    }

    for(int i=0;i<m;i++){
        cin >> a >> b;
        cout << query(0, n-1, a-1, n-1, root[b]) << endl;
    }

    return 0;
}
