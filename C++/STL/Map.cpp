// Map - Variação da estrutura set - Red-Black Trees
	// Set armazena apenas uma chave
	// Map armazena uma chave e um valor associado

map<string, int> M; // Mapeia strings em int

//S.insert()

	M.insert(make_pair("Tiago", 18));
	//ou
	M["Tiago"]=18; // Relacionando o valor 18 a chave Tiago
				//   Complexidade O(logN)

//S.find()

	if(M.find("Tiago") != M.end()) // Caso Tiago esteja no conjunto
							// O(logN)
						   //  Retorna um ponteiro que aponta para o elemento procurado
	cout << M["Tiago"] << endl; // Imprime o valor associado ao nome (10)

//S.erase

	M.erase("Tiago"); // Apaga o elemento 10 do set
				// O(logN)

//S.count()

	if(S.count(N)) // retorna 1 caso o elemento N esteja no map, 0 caso contrário

//Outros

	M.clear(); // Apaga todos os elementos
	M.size(); // Retorna a quantidade de elementos
	M.begin(); //Retorna um ponteiro para o inicio do map
	M.end();  //Retorna um ponteiro para o final do map

// Acessa os elementos do map de forma ordenada (map<int>::iterator)
	
	for(map<string,int>::iterator it=M.begin(); it!=M.end(); it++)
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}