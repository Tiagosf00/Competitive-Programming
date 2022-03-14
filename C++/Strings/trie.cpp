struct Trie{

    int trie[MAX][26];
    bool finish[MAX];
    int nxt = 1, len = 0;

    void add(string s){
        int node = 0;
        for(auto c: s){
            if(trie[node][c-'a'] == 0)
                node = trie[node][c-'a'] = nxt++;
            else
                node = trie[node][c-'a'];
        }
        if(!finish[node]){
            finish[node] = true;
            len++;
        }
    }

    bool find(string s, bool remove=false){
        int node = 0;
        for(auto c: s)
            if(trie[node][c-'a'] == 0)
                return false;
            else
                node = trie[node][c-'a'];
        if(remove and finish[node]){
            finish[node]=false;
            len--;
        }
        return finish[node];
    }
};