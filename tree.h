// binary lofting and find lca
vector<vector<int>> dp;
vector<int> d;
void dfs(int node, int p, vector<vector<int>> &tree, int dep) {
    dp[node][0] = p;
    d[node] = dep;

    for (int i = 1; i <= 19; i++) {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto v : tree[node]) {
        if (v == p) continue;
        dfs(v, node, tree, dep + 1);
    }
}

int lca(int a, int b) {
    if (d[a] < d[b]) swap(a, b);

    int diff = d[a] - d[b];

    for (int i = 0; i <= 19; i++) {
        if ((diff >> i) & 1) {
            a = dp[a][i];
        }
    }
    
    if (a == b) {
        return a;
    }

    for (int i = 19; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        } 
    }

    return dp[a][0];
}

//input
vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }