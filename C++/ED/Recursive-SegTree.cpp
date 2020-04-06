// Segment Tree Recursiva - Range maximum query

int val[4*MAX];
int vet[MAX];

void monta(int i, int j, int no){
	if(i==j){
		val[no]=vet[i];
		return;
	}

	int esq = 2*no;
	int dir = 2*no+1;
	int meio = (i+j)/2;

	monta(i, meio, esq);
	monta(meio+1, j, dir);

	val[no]=max(val[esq], val[dir]);
}
 
void atualiza(int no, int i, int j, int pos, int novo_valor){
	if(i==j){
		val[no]=novo_valor;
	}else{
		int esq = 2*no;
		int dir = 2*no+1;
		int meio = (i+j)/2;
 
		if(pos<=meio)
			atualiza(esq, i, meio, pos, novo_valor);
		else
			atualiza(dir, meio+1, j, pos, novo_valor);
 
		if(val[esq]>val[dir])
			val[no]=val[esq];
		else
			val[no]=val[dir];
	}
}
 
int consulta(int no, int i, int j, int A, int B){
	if(i>B || j<A)
		return -1;
	if(i>=A and j<=B)
		return val[no];
 
	int esq = 2*no;
	int dir = 2*no+1;
	int meio = (i+j)/2;
 
	int resp_esq = consulta(esq, i, meio, A, B);
	int resp_dir = consulta(dir, meio+1, j, A, B);
 
	if(resp_dir==-1)
		return resp_esq;
	if(resp_esq==-1)
		return resp_dir;
 
	if(resp_esq>resp_dir)
		return resp_esq;
	else
		return resp_dir;
}

int main()
{
	monta(1, N, 1);
	atualiza(1, 1, N, pos, valor);
	x = consulta(1, 1, N, inicio, fim);
}