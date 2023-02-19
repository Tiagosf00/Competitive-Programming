struct Trie{

    int trie[N][10];
    bool finish[N];
    int nxt = 1, len = 0;

    void add(string s){
        int node = 0;
        for(auto c: s){
            if(trie[node][c-'0'] == 0)
                node = trie[node][c-'0'] = nxt++;
            else
                node = trie[node][c-'0'];
        }
        if(!finish[node]){
            finish[node] = true;
            len++;
        }
    }

    bool find(string s, bool remove=false){
        int node = 0;
        for(auto c: s)
            if(trie[node][c-'0'] == 0)
                return false;
            else
                node = trie[node][c-'0'];
        if(remove and finish[node]){
            finish[node]=false;
            len--;
        }
        return finish[node];
    }

    string best_xor(string s){
        int node = 0;
        string ans;
        for(auto c: s){
            char other='1'; if(c=='1') other='0';

            if(trie[node][other-'0'] != 0){
                node = trie[node][other-'0'];
                if(other=='1') ans.pb('1');
                else ans.pb('0');
            }else{
                node = trie[node][c-'0'];
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
    reverse(ans.begin(), ans.end());
    return ans;
}