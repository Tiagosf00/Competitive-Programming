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

//pop_back()

	V.pop_back(); // Apaga o último elemento do vector V

//clear()

	V.clear(); // Remove todos os elementos do vector V
	sort(V.begin(), V.end()); // Ordena o vector

//upper_bound e lower_bound

	vector<int>::iterator low,up;
	low=lower_bound(v.begin(), v.end(), 20);
	up=upper_bound(v.begin(), v.end(), 20);
	cout << "lower_bound at position " << (low- v.begin()) << '\n';
	cout << "upper_bound at position " << (up - v.begin()) << '\n';

//binary_search
		if(binary_search(vet.begin(), vet.end(), 15))