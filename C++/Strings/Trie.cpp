int trie[MAX][26];
bool finish[MAX];
int nxt = 1;

void Add(string &str){
    int node = 0;
    for(auto s: str){
        if(trie[node][s-'a'] == 0){
            node = trie[node][s-'a'] = nxt;
            nxt++;
        }else
            node = trie[node][s-'a'];
    }
    finish[node] = true;
}

bool Find(string &str){
    int idx = 0;
    for(auto s: str)
        if(trie[idx][s-'a'] == 0)
            return false;
        else
            idx = trie[idx][s-'a'];
    return finish[idx];
}
