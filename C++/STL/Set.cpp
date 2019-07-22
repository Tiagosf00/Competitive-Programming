// Set - Red-Black Trees - Árvore rubro negra
// Busca, inserção e deleção em O(logn)

set<int> S;

//S.insert()

	S.insert(10); // Adiciona 10 ao set
				 //  Não adiciona elementos repetidos
				//   Complexidade O(logN)

//S.find()

	if(S.find(3) != S.end()) // Caso 3 esteja no conjunto
							//  O(logN)
						   //   Retorna um ponteiro que aponta para o elemento procurado

//S.erase
		
	S.erase(10); // Apaga o elemento 10 do set

	//Outros
	S.clear(); // Apaga todos os elementos
	S.size(); // Retorna a quantidade de elementos
	S.begin(); // Retorna um ponteiro para o inicio do set
	S.end();  // Retorna um ponteiro para o final do set

	p = S.lower_bound(n); // Retorna um ponteiro para o primeiro elemento maior ou igual a n (not less than n)
	p = S.upper_bound(n); // Retorna um ponteiro para o primeiro elemento maior que n (greater than n)


// Acessa os elementos do set de forma ordenada (set<int>::iterator)

	for(set<int>::iterator it=S.begin(); it!=S.end(); it++)
	{
		cout << *it << " ";
	}
