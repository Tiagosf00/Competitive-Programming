struct node{ 
    int pos, l, r, val;
    bool operator<(node &o){
        if(val==o.val) return l>o.l;
        return val>o.val;
    }
};

struct FT {
    vector<int> bit;  // indexado em 0
    int n;

    FT(int n) {
        this->n = n+1;
        bit.assign(n+1, 0);
    }

    int sum(int idx) {
        int ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

vi solveQuery(vi arr, vi ql, vi qr, vi qk){ 
	// indexing [l, r] in 1
    int n = arr.size();
    int q = qk.size();
    node a[n+q]; 

    for(int i=0;i<n;i++){ 
        a[i].val = arr[i]; 
        a[i].pos = a[i].l = 0; 
        a[i].r = i+1; 
    } 

    for(int i=n;i<n+q;i++){
        a[i].pos = i+1-n;
        a[i].val = qk[i-n];
        a[i].l = ql[i-n];
        a[i].r = qr[i-n];
    }
    sort(a, a+n+q);

    FT ft(n);
    vi ans(q+1, 0);

    for(int i=0;i<n+q;i++){
        if(a[i].pos != 0)
            ans[a[i].pos] = ft.sum(a[i].l, a[i].r);
        else
            ft.add(a[i].r, 1);
    } 
    return ans;
}
int main() 
{ 
	vi arr = { 7, 3, 9, 13, 5, 4 }; 

	vi QueryL = { 1, 2 }; 
	vi QueryR = { 4, 6 }; 

	vi QueryK = { 6, 8 }; 

	solveQuery(arr, QueryL, QueryR, QueryK); 

	return 0; 
} 
