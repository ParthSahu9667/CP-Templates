template <typename num_t>
struct fenwick {
    int n;
    vector<num_t> bit;

    void init(int s, vector<num_t>& arr) {
        n = s;
        bit.assign(n + 1, num_t(0));
        for (int i = 0; i < n; ++i) add(i, arr[i]);
    }

    void init(int s) {
        n = s;
        bit.assign(n + 1, num_t(0));
    }

    // set position pos to value v (0-indexed)
    void update(int pos, num_t v) {
        num_t curr = get(pos);
        add(pos, v - curr);
    }

    // add delta to position pos (pos is 0-indexed)
    void add(int pos, num_t delta) {
        int i = pos + 1;
        while (i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    // get single element at pos (0-indexed)
    num_t get(int pos) {
        return query(pos, pos);
    }

    // range query [l..r] (both 0-indexed). If l>r returns neutral element.
    num_t query(int l, int r) {
        if (l > r) return num_t(0);
        return prefix(r) - prefix(l - 1);
    }

    // prefix sum [0..pos] (pos is 0-indexed). If pos < 0 returns neutral element.
    num_t prefix(int pos) {
        if (pos < 0) return num_t(0);
        num_t res = num_t(0);
        int i = pos + 1;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};
