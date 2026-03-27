// vector
vector<int> kmp(vector<int> a) {
    int n = a.size();
    vector<int> dp(n);

    for (int i = 1; i < n; i++) {
        int j = dp[i - 1];
        while (j > 0 && a[i] != a[j]) {
            j = dp[j - 1];
        }
        if (a[i] == a[j]) {
            j++;
        }
        dp[i] = j;
    }
    
    return dp;
}


// string
vector<int> kmp(string s) {
    int n = s.length();
    vector<int> dp(n);
    for (int i = 1; i < n; i++) {
        int j = dp[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = dp[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        dp[i] = j;
    }
    return dp;
}
