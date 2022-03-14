string p;
int neighbor[N];
int walk(int u, char c) { // leader after inputting `c`
    while (u != -1 && (u+1 >= (int)p.size() || p[u + 1] != c)) // leader doesn't match
        u = neighbor[u];
    return p[u + 1] == c ? u+1 : u;
}
void build() {
    neighbor[0] = -1; // -1 is the leftmost state
    for (int i = 1; i < (int)p.size(); i++)
        neighbor[i] = walk(neighbor[i-1], p[i]);
}
