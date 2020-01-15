vector<int> preffix_function(const string &s){
	int n = s.size(); vector<int> b(n+1);
	b[0] = -1; int i = 0, j = -1;
	while(i < n){
		while(j >= 0 && s[i] != s[j]) j = b[j];
		b[++i] = ++j;
	}
	return b;
}
void kmp(const string &t, const string &p){
	vector<int> b = preffix_function(p);
	int n = t.size(), m = p.size();
	int j = 0;
	for(int i = 0; i < n; i++){
		while(j >= 0 && t[i] != p[j]) j = b[j];
		j++;
		if(j == m){

			j = b[j];
		}
	}
}
