int val[4*MAX];
int vet[MAX];
int N;

int merge(int a, int b){
    return max(a, b);
}

void build(int i=1, int j=N, int no=1){
    if(i==j){
        val[no]=vet[i];
        return;
    }

    int meio = (i+j)/2;

    build(i, meio, no<<1);
    build(meio+1, j, no<<1|1);

    val[no]=merge(val[no<<1], val[no<<1|1]);
}
 
void update(int pos, int x, int no=1, int i=1, int j=N){
    if(i==j){
        val[no]=x;
        return;
    }
    int meio = (i+j)/2;

    if(pos<=meio)
        update(pos, x, no<<1, i, meio);
    else
        update(pos, x, no<<1|1, meio+1, j);

    val[no]=merge(val[no<<1], val[no<<1|1]);
    
}
 
int query(int A, int B, int i=1, int j=N, int no=1){
    if(B<i or j<A)
        return INF;
    if(A<=i and j<=B)
        return val[no];
 
    int mid = (i+j)/2;
 
    int ansl = query(A, B, i, mid, no<<1);
    int ansr = query(A, B, mid+1, j, no<<1|1);
 
    if(ansr==INF) return ansl;
    if(ansl==INF) return ansr;
 
    return merge(ansl, ansr);
}

int main()
{
	build();
	update(pos, valor);
	x = query(l, r);
}