template <typename num_t>
struct sparse_table {
    int n;
    int LOG;
    vector<vector<num_t>> st;
    vector<int> lg;

    void init(int s, vector<num_t>& arr) {
        n = s;
        if (n <= 0) {
            LOG = 0;
            st.clear();
            lg.assign(1, 0);
            return;
        }

        // lg is floor(log2(i))
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
        LOG = lg[n] + 1;

        st.assign(LOG, vector<num_t>(n));
        for (int i = 0; i < n; i++) {
            st[0][i] = arr[i];
        }

        for (int k = 1; k < LOG; k++) {
            int len = 1 << k;
            int half = 1 << (k - 1);
            for (int i = 0; i + len - 1 < n; i++) {
                st[k][i] = combine(st[k - 1][i], st[k - 1][i + half]);
            }
        }
    }

    inline num_t combine(num_t &a, num_t &b) {
        return max(a, b); // change function here
    }

    inline num_t query(int l, int r) {
        if (l > r) return 0; // change return statement here as well
        if (l < 0) l = 0;
        if (r >= n) r = n - 1;
        int len = r - l + 1;
        int k = lg[len];
        return combine(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
