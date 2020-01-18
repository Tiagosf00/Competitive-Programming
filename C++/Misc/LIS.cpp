multiset<int> S;
for(int i = 0; i < n; i++){
	auto it = S.upper_bound(vet[i]); // low for inc
	if(it != S.end())
		S.erase(it);
	S.insert(vet[i]);
}
// size of the lis
int ans = S.size();