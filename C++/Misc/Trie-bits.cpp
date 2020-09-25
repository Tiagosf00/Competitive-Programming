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

    string best_xor(string s){
        int idx = 0;
        string ans;
        for(auto c: s){
            char other='1'; if(c=='1') other='0';

            if(trie[idx][other-'0'] != 0){
                idx = trie[idx][other-'0'];
                if(other=='1') ans.pb('1');
                else ans.pb('0');
            }else{
                idx = trie[idx][c-'0'];
                if(c=='1') ans.pb('1');
                else ans.pb('0');
            }
        }
             
        return ans;
    }
    
};

string sbits(ll n){
    string ans;
    for(int i=0;i<64;i++)
        ans.pb(!!(n & 1LL<<i)+'0');
    return ans;
}