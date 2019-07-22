pair<string, int> P; // Pair de string e int

cin>>P.first>>P.second; // Lê primeiro a string depois o inteiro

// Pair de pair (Struct mais aconselhável)

	pair<string, pair<double, double>> P; // Cria uma variável pair

	P.first = "Joao"; // Nome de um aluno
	P.second.first = 8.2; // Primeira nota do aluno
	P.second.second = 10; // Segunda nota do aluno

// Possui operador de desigualdade implementado

	A.first > B.first //Strings, ints...

// Vector de pair

	vector<pair<int, string> > V;
	sort(V.begin(), V.end()); //Ordena o vetor utilizando o comparador de desigualdade do pair, ou seja, primeiro ordena (crescentemente) pelo first e em caso de empate ordena pelo second.

//make.pair()

	P = make_pair("Joao", 10); //retorna um pair<string, int>

	for(int i=1;i<10;i++)
	{  
        cin>>a>>b;
        V.push_back(make_pair(a,b));
    }