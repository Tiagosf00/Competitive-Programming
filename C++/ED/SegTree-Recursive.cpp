int val[4*MAX];
int vet[MAX];

int merge(int a, int b){
    return max(a, b);
}

void build(int i, int j, int no){
    if(i==j){
        val[no]=vet[i];
        return;
    }

    int meio = (i+j)/2;

    build(i, meio, no<<1);
    build(meio+1, j, no<<1|1);

    val[no]=merge(val[no<<1], val[no<<1|1]);
}
 
void update(int no, int i, int j, int pos, int x){
    if(i==j){
        val[no]=x;
        return;
    }
    int meio = (i+j)/2;

    if(pos<=meio)
        update(no<<1, i, meio, pos, x);
    else
        update(no<<1|1, meio+1, j, pos, x);

    val[no]=merge(val[no<<1], val[no<<1|1]);
    
}
 
int query(int no, int i, int j, int A, int B){
    if(i>B || j<A)
        return -1;
    if(i>=A and j<=B)
        return val[no];
 
    int mid = (i+j)/2;
 
    int ansl = query(no<<1, i, mid, A, B);
    int ansr = query(no<<1|1, mid+1, j, A, B);
 
    if(ansr==-1)
        return ansl;
    if(ansl==-1)
        return ansr;
 
    return merge(ansl, ansr);
}

int main()
{
	build(1, N, 1);
	update(1, 1, N, pos, valor);
	x = query(1, 1, N, inicio, fim);
}