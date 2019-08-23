pair<string, int> P;

cin>>P.first>>P.second;

// Pair of pair

	pair<string, pair<double, double>> P;

	P.first = "Joao";
	P.second.first = 8.2;
	P.second.second = 10;

// Vector of pair

	vector<pair<int, string> > V;
	sort(V.begin(), V.end());

//make.pair()

	P = make_pair("Joao", 10);

	for(int i=1;i<10;i++)
	{  
        cin>>a>>b;
        V.push_back(make_pair(a,b));
    }