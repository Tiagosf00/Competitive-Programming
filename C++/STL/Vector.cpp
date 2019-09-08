// Vector - Vetor

vector<int> V;
vector<tipo> nome;
vector<tipo> V(n, value);

//push_back()

	V.push_back(2);
	V.push_front(2);

// front() back()

	cout << V.front() << endl;
	cout << V.back() << endl;

//size()

	tamanho = V.size();

//resize()

	V.resize(10);
	V.resize(n, k);

//pop_back()

	V.pop_back();

//clear()

	V.clear();
	sort(V.begin(), V.end());

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
	//first - pointer to the first element
	//last - last element
	//sum - inicial value
	//func

	int func(int x, int y)  
	{
		//return x*y;
		return x+y;
	}

//partial_sum()

	partial_sum(first, last, vet, func);

	int func(int x, int y)  
	{
		//return x*y;
		return x+y;
	}

//assign()
	//Diferente do resize() por mudar o valor de todos os elementos do vector

	vector<int> vet;
	vet.assign(N, x);

	vector< vector<int> > vet;
	vet.assign(N, vector<int>());

//sort()

	sort(vet, vet+N, func);

	bool func(Aluno a, Aluno b)
	{
		return a.nota < b.nota; // True caso a venha antes de b, False caso contrario
	}

//fill()
	
	vector<int> vet(5); // 0 0 0 0 0

	fill(vet.begin(), vet.begin()+2, 8); // 8 8 0 0 0