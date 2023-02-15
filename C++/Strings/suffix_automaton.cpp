const int SA = 2*N; // Node 1 is the initial node of the automaton
int last = 1;
#define link my_link
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

    if (p == 0) { link[u] = 1; return; }

    int q = to[p][c];
    if (len[q] == len[p] + 1) { link[u] = q; return; }

    int clone = ++lastID;
    len[clone] = len[p] + 1;
    link[clone] = link[q];
    link[q] = link[u] = clone;
    to[clone] = to[q];
    for (int pp = p; to[pp][c] == q; pp = link[pp])
        to[pp][c] = clone;
}
