class disjoint_set {
    public:
    vector<int> p;
    vector<int> size;
    disjoint_set (int n) {
        p.resize(n + 1);
        size.resize(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    } 

    int parent (int u) {
        if (p[u] == u) return u;
        return p[u] = parent(p[u]);
    }

    bool add_edge(int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x == y) return false;
        
        if (size[x] > size[y]) swap(x, y);
        
        p[x] = y;
        size[y] += size[x];
        
        return true;
    }

};