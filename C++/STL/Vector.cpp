// Vector - Vetor

vector<int> V; // Vector de inteiros
vector<tipo> nome;
vector<tipo> V(n, value); //n elementos = value

//push_back()

	V.push_back(2); // Adiciona o valor 2 ao final do vector V
	V.push_front(2);// Adiciona o valor 2 ao início do vector V

//size()

	tamanho = V.size(); // Retorna um valor que representa o nº do vector

//resize()

	V.resize(10); // Muda o tamanho do vector para 10
				 //  Caso seja maior que o vector original, os novos elementos adicionados são nulos
	V.resize(n, k); // Muda o tamanho do vetor para n, e para cada elemento novo no vector é atribuido o valor de k

//pop_back()

	V.pop_back(); // Apaga o último elemento do vector V

//clear()

	V.clear(); // Remove todos os elementos do vector V
	sort(V.begin(), V.end()); // Ordena o vector

//upper_bound() e lower_bound()

	vector<int>::iterator low,up;
	low=lower_bound(v.begin(), v.end(), 20);
	up=upper_bound(v.begin(), v.end(), 20);
	cout << "lower_bound at position " << (low- v.begin()) << '\n';
	cout << "upper_bound at position " << (up - v.begin()) << '\n';

//binary_search()

	if(binary_search(vet.begin(), vet.end(), 15))

//accumulate()
	
	cout << accumulate(first, last, sum, func) << endl;
	//first - ponteiro para primeiro elemento
	//last - ponteiro para último elemento
	//sum - valor inicial
	//func - função que acumula termo a termo (não obrigatória)

	int func(int x, int y)  
	{
		//return x*y;
		return x+y;
	}

//partial_sum()

	partial_sum(first, last, vet, func);
	//first - ponteiro para primeiro elemento
	//last - ponteiro para último elemento
	//vet - vetor onde será colocado os valores
	//func - função que acumula termo a termo (não obrigatória)

	int func(int x, int y)  
	{
		//return x*y;
		return x+y;
	}

//assign()
	//Diferente do resize() por mudar o valor de todos os elementos do vector

	vector<int> vet;
	vet.assign(N, x); //Atribui o valor das N variáveis a x

	vector< vector<int> > vet;
	vet.assign(N, vector<int>());
