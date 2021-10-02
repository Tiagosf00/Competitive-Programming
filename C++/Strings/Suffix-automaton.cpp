// Node 1 is the initial node of the automaton
const int SA = 2 * N;
int last = 1;
int len[SA], link[SA];
array<int, 26> to[SA]; // maybe map<int, int>
int lastID = 1;

void push(int c) {
    int u = ++lastID;
    len[u] = len[last] + 1;

    int p = last;
    last = u; // update last immediately
    for (; p > 0 && !to[p][c]; p = link[p])
        to[p][c] = u;

    if (p == 0) {
        // this was the first time the character c was added to the string
        link[u] = 1;
        return;
    }

    // there's a transition from a substring to { substring c } (from p to q)
    int q = to[p][c];
    if (len[q] == len[p] + 1) {
        // continuous transition
        // we can just add u to the endpos-set of q and be fine
        link[u] = q;
        return;
    }

    // non-continuous transition
    // we need to split q into two distinct endpos-sets
    int clone = ++lastID;
    len[clone] = len[p] + 1;
    link[clone] = link[q];
    link[q] = link[u] = clone;
    to[clone] = to[q];
    for (int pp = p; to[pp][c] == q; pp = link[pp])
        to[pp][c] = clone;
}

void print_automaton(const vector<int> &nodes) {
    printf("------------------------------\n");
    for (int u : nodes) {
        for (int c = 0; c < 26; c++) {
            if (to[u][c])
                printf("%d -- %c --> %d\n", u, c + 'a', to[u][c]);
        }
    }
    printf("------------------------------\n");
}
