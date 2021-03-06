struct Trie{

    int trie[MAX][26];
    bool finish[MAX];
    int nxt = 1, len = 0;

    void add(string &s){
        int node = 0;
        for(auto c: s){
            if(trie[node][c-'a'] == 0){
                node = trie[node][c-'a'] = nxt;
                nxt++;
            }else
                node = trie[node][c-'a'];
        }
        if(!finish[node]){
            finish[node] = true;
            len++;
        }
    }

    bool find(string &s, bool remove){
        int idx = 0;
        for(auto c: s)
            if(trie[idx][c-'a'] == 0)
                return false;
            else
                idx = trie[idx][c-'a'];
        if(remove and finish[idx]){
            finish[idx]=false;
            len--;
        }
        return finish[idx];
    }

    bool find(string &s){
        return find(s, 0);
    }

    void del(string &s){
        find(s, 1);
    }
    
};