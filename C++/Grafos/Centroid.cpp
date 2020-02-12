vi g[MAX];
int size[MAX];
bool erased[MAX]; // vetor dos vertices apagados na decomp.

int sz(int u, int p) {
  int s = 1;
  for(auto prox : g[u]) {
    if(prox != p and !erased[prox])
      s += sz(prox, u);
  }
  return size[u] = s;
}

int centroid(int u, int p, int n) {
  // chamar funcao sz antes, n = size[u]
  for(auto prox : g[u]) {
    if(prox != p and !erased[prox]) {
      if(size[prox] > n/2) {
        return centroid(prox, u, n);
      }
    }
  }
  return u;
}
