// Set - Red-Black Trees - O(logn)

set<int> S;

//S.insert()

	S.insert(10); // O(logN)

//S.find()

	if(S.find(3) != S.end())//  O(logN)

//S.erase
		
	S.erase(10);

	//Outros
	S.clear();
	S.size();
	S.begin();
	S.end();

	p = S.lower_bound(n); // Retorna um ponteiro para o primeiro elemento maior ou igual a n (not less than n)
	p = S.upper_bound(n); // Retorna um ponteiro para o primeiro elemento maior que n (greater than n)


// (set<int>::iterator)

	for(set<int>::iterator it=S.begin(); it!=S.end(); it++)
	{
		cout << *it << " ";
	}
