pii tree[4*MAX];
int lazy[4*MAX];
int N, vet[MAX];

// Segtree de mínimo e quantidade com lazy

pii merge(pii a, pii b){
    if(a.ff == b.ff) return {a.ff, a.ss+b.ss};
    return min(a, b);
}

void prop(int no, bool leaf){
    if(lazy[no] != 0){
        tree[no].ff += lazy[no];
        if(!leaf){
            lazy[no<<1] += lazy[no];
            lazy[no<<1|1] += lazy[no];
        }
        lazy[no] = 0;
    }
}

void build(int i=1, int j=N, int no=1){
    if(i==j){
        tree[no].ff = vet[i];
        tree[no].ss = 1;
        return;
    }

    int mid = (i+j)/2;

    build(i, mid, no<<1);
    build(mid+1, j, no<<1|1);

    tree[no]=merge(tree[no<<1], tree[no<<1|1]);
}
 
void update(int l, int r, int x, int no=1, int i=1, int j=N){
    prop(no, i==j);
    if(r<i or j<l) return;
    if(l<=i and j<=r){
        lazy[no] += x;
        prop(no, i==j);
        return;
    }
    int mid = (i+j)/2;

    update(l, r, x, no<<1, i, mid);
    update(l, r, x, no<<1|1, mid+1, j);

    tree[no] = merge(tree[no<<1], tree[no<<1|1]);
    
}
 
pii query(int l, int r, int i=1, int j=N, int no=1){
    prop(no, i==j);
    if(r<i or j<l) return {INF, 0};
    if(l<=i and j<=r) return tree[no];
 
    int mid = (i+j)/2;

    return merge(query(l, r, i, mid, no<<1),
                 query(l, r, mid+1, j, no<<1|1));
}