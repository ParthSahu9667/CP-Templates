class disjoint_set {
    public:
    vector<int> p;
    vector<int> size;
    stack<array<int, 4>> st;

    disjoint_set (int n) {
        p.resize(n + 1);
        size.resize(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    } 
    // we cant have path compression with rollback
    int parent (int u) {
        while (u != p[u]) {
            u = p[u];
        }
        return u;
    }

    bool add_edge(int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x == y) {
            st.push({-1, -1, -1, -1});
            return false;
        }
        
        if (size[x] > size[y]) swap(x, y);
        
        st.push({x, p[x], y, size[y]});
        p[x] = y;
        size[y] += size[x];
        
        return true;
    }


    void rollback () {
        auto [x, px, y, szy] = st.top();
        st.pop();

        if (x == -1) {
            return;
        }

        p[x] = px;
        size[y] = szy;
    }
};
