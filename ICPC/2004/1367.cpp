#include <bits/stdc++.h>
using namespace std;

typedef struct Prob{
	int time, solved;
}Prob;

int main()
{

	int n;
	while(cin >> n && n){
		map<char, Prob> s;
		char c;
		int time;
		string ver;
		map<char, Prob>::iterator it;
		for(int i=0;i<n;i++){
			cin >> c >> time >> ver;
			it = s.find(c);
			if(it == s.end()){
				if(ver.compare("correct") == 0){
					s.insert({c, {time, 1}});
				}else{
					s.insert({c, {20, 0}});	
				}
			}else{
				if(ver.compare("incorrect") == 0){
					if(!s[c].solved){
						s[c].time+=20;
					}
				}else{
					if(!s[c].solved){
						s[c].time += time;
						s[c].solved = 1;
					}
				}
			}			
		}

		int S = 0, p = 0;
		for(it=s.begin();it!=s.end();it++){
			Prob x = it->second;
			if(x.solved){
				S++;
				p+=x.time;
			}
		}
		cout << S << " " << p << endl;
	}

	return 0;
}
