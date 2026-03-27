    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 2>>> g(n + 1);
    vector<array<int, 3>> edges;
    vector<long long> dp(n + 1, 1e18), mark(n + 1, 0), vis(n + 1, 0);
    dp[1] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        g[b].push_back({a, c});
        edges.push_back({a, b, -c});
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int c = edges[j][2];

            if (dp[u] != 1e18 && dp[v] > dp[u] + c) {
                dp[v] = dp[u] + c;
            }
        }
    }
    
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int c = edges[j][2];
        
        if (dp[u] != 1e18 && dp[v] > dp[u] + c) {
            dp[v] = dp[u] + c;
            mark[v] = 1;
        }
    }