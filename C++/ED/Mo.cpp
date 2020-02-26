const int BLK = 500; // tamanho do bloco, algo entre 300 e 500 e nice

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / BLK, r) <
        make_pair(other.l / BLK, other.r);
    }
};

void add(); void remove() // implementar operacoes de acordo com o problema, cuidado com TLE ao utilizar MAP

vector<pair<int,ll>> mo() {
    vector<pair<int,ll>> res;
    sort(queries.begin(), queries.end());

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
        res.pb(mp(q.idx, RESPOSTA)); // adicionar resposta de acordo com o problema
     }
     return res; // ordernar o vetor pelo indice e responder queries na ordem
}
