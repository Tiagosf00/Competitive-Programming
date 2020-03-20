class Trie {
private:
   struct Node {
      map<char, Node*> children;
      int qt = 0;
      ll size = 0;
   };

   Node* root;

   void dfs(Node* cur) {
     ll sz = 1;

     for(auto prox : cur->children) {
         dfs(prox.second);
         sz += (prox.second)->size;
     }

     cur->size = sz;
   }

    void del(Node* cur, int dep, string &s) {
        if(dep >= 32)
            return;

        Node* prox = cur->children[s[dep]];
        prox->qt--;
        del(prox, dep+1, s);

        if(prox->qt == 0)
           cur->children.erase(s[dep]);
    }

public:
   Trie() {
      root = new Node();
      root->qt = 1;
   }

   void add(string s) {
      Node* cur = root;

      for(auto c : s) {
         if(cur->children.count(c) == 0) {
            cur->children[c] = new Node();
         }
         cur->children[c]->qt++;
         cur = cur->children[c];
      }
   }

   void del(string &s) {
       Node* cur = root;
       del(cur, 0, s);
   }

   void size() {
       this->dfs(root);
   }
};
