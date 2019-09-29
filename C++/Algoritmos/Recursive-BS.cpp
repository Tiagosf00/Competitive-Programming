// Recursive binary search

int bs(int x, int ini, int fim)
{
	if(fim>=ini)
	{
		int meio = (ini+fim)/2;

		if(vetor[meio]==x)
			return x;

		if(vetor[meio]>x)
			return bs(x, ini, meio-1);
		else
			return bs(x, meio+1, fim);
	}

	return -1;
}
