const int BLK = 600; // tamanho do bloco, algo entre 500 e 700 eh nice

struct Query {
    int l, r, idx;
    Query(int l, int r, int idx) {
        this->l = l;
        this->r = r;
        this->idx = idx;
    }
    bool operator<(Query other) const {
        if(l/BLK != other.l/BLK)
            return l/BLK < other.l/BLK;
        return (l/BLK & 1) ? r < other.r : r > other.r;
    }
};

inline void add() {} 
inline void remove() {} // implementar operacoes de acordo com o problema

vector<int> mo(vector<Query>& queries) {
    vector<int> res(queries.size());
    sort(queries.begin(), queries.end());
    resposta = 0;

    int l = 0, r = -1;
    for(Query q : queries) {
        while(l > q.l) {
                l--;
                add(l);
        }
        while(r < q.r) {
                r++;
                add(r);
        }
        while(l < q.l) {
                remove(l);
                l++;
        }
        while(r > q.r) {
                remove(r);
                r--;
        }
        res[q.idx] = resposta; // adicionar resposta de acordo com o problema
     }
     return res; // ordernar o vetor pelo indice e responder queries na ordem
}
