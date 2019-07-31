// Segment Tree Recursiva - Range maximum query

vector<long> val(MAX, 0);
 
void atualiza(int no, int i, int j, int pos, int novo_valor)
{
	if(i==j)
	{
		val[no]=novo_valor;
	}else
	{
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
 
int consulta(int no, int i, int j, int A, int B)
{
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
	atualiza(1, 1, N, pos, valor);
	x = consulta(1, 1, N, inicio, fim);
}