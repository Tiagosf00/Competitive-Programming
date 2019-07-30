// Delta encoding

for(int i=0;i<q;i++) // Armazenando as mudanças no vetor delta
{
    int l,r,x;
    cin >> l >> r >> x; // Adicionar x de l até r
    delta[l] += x;
    delta[r+1] -= x;
}

int atual = 0;
	
for(int i=0;i<n;i++) // Atualizando o vetor
{
    atual += delta[i];
    v[i] += atual;
}