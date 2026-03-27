const int N = 2e5 + 1, M = 20;
 
vector<int> dep(N);
vector<vector<int>> Par(N, vector<int> (M)), g(N);

void dfs(int cur, int par) {
    dep[cur] = dep[par] + 1;
    Par[cur][0] = par;
    for (int j = 1; j < M; j++) Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    for (auto x : g[cur]) if (x != par)  dfs(x, cur);
}

int LCA(int u, int v) {
    if (u == v) return u;
    if (dep[u] < dep[v]) swap(u, v);
    // u is deeper

    int diff = dep[u] - dep[v];
    for (int j = M - 1; j >= 0; j--){
        if ((diff >> j) & 1) u = Par[u][j];
    }
 
    for (int j = M - 1; j >= 0; j--){
        if (Par[u][j] != Par[v][j]){
            u = Par[u][j];
            v = Par[v][j];
        }
    }

    return (u != v ? Par[u][0] : u);
}