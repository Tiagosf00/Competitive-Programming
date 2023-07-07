const int BLK = 600; // tamanho do bloco, algo entre 500 e 700 eh nice

struct Query {
    int l, r, idx;
    Query(int l, int r, int idx): l(l), r(r), idx(idx) {}
    bool operator<(Query other) const {
        if(l/BLK != other.l/BLK)
            return l/BLK < other.l/BLK;
        return (l/BLK & 1) ? r < other.r : r > other.r;
    }
};

int ans = 0;
inline void add() {} 
inline void remove() {} // implementar operacoes de acordo com o problema

vector<int> mo(vector<Query>& queries) {
    vector<int> res(queries.size());
    sort(queries.begin(), queries.end());
    ans = 0;

    int l = 0, r = -1;
    for(Query q : queries) {
        while(l > q.l) add(--l);
        while(r < q.r) add(++r);
        while(l < q.l) remove(l++);
        while(r > q.r) remove(r--);
        res[q.idx] = ans;
    }
    return res;
}
