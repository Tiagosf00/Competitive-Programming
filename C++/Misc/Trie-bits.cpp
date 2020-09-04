struct Trie{

    int trie[MAX][10];
    bool finish[MAX];
    int nxt = 1, len = 0;

    void add(string &s){
        int node = 0;
        for(auto c: s){
            if(trie[node][c-'0'] == 0){
                node = trie[node][c-'0'] = nxt;
                nxt++;
            }else
                node = trie[node][c-'0'];
        }
        if(!finish[node]){
            finish[node] = true;
            len++;
        }
    }

    bool find(string &s, bool remove){
        int idx = 0;
        for(auto c: s)
            if(trie[idx][c-'0'] == 0)
                return false;
            else
                idx = trie[idx][c-'0'];
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

string sbits(ll n){
    string ans;
    for(int i=0;i<64;i++)
        ans.pb((n & 1LL<<i)+'0');
    return ans;
}