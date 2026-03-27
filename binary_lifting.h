const int N = 2e5 + 1, M = 20;
 
vector<int> adj[N];
int dep[N], Par[N][M];
 
void dfs(int cur, int par) {
    dep[cur] = dep[par] + 1;
    Par[cur][0] = par;
    for (int j = 1; j < M; j++) Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    for (auto x : adj[cur]) if (x != par)  dfs(x, cur);
}
 
int KthParent(int u, int k) {
    for(int i = M - 1; i >= 0; i--) {
        if((1 << i) & k) u = Par[u][i];
    }
    return u;
}
 
int main() {
 
    int n, q; cin >> n >> q;
 
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }
 
    dfs(1, 0);
 
    for(int i = 0; i < q; i++) {
        int u, k; cin >> u >> k;
        int parent = KthParent(u, k);
        cout << (parent == 0 ? -1 : parent) << "\n";
    }
}