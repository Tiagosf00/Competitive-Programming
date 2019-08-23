// Map - Red-Black Trees

map<string, int> M;

//S.insert()

	M.insert(make_pair("Tiago", 18));
	//ou
	M["Tiago"]=18; // O(logN)

//S.find()

	if(M.find("Tiago") != M.end()) // O(logN)

	cout << M["Tiago"] << endl;

//S.erase

	M.erase("Tiago"); // O(logN)


//S.count()

	if(S.count(N))

//Outher

	M.clear();
	M.size();
	M.begin();
	M.end();

// (map<int>::iterator)
	
	for(map<string,int>::iterator it=M.begin(); it!=M.end(); it++)
	{
		cout << "(" << it->first << ", " << it->second << ") ";
	}
