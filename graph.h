int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

//weighted graph
int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> graph(n + 1);
    vector<long long> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;

        graph[u].push_back({v, a});
        graph[v].push_back({u, a});
    }


int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

//bfs for depth
queue<pair<int, int>> q;
        vector<int> vis(n);
        vis[0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
 
            for (auto v : tree[node]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, dis + 1});
                }
            }
        }
