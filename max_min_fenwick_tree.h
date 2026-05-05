template <typename num_t>
struct fenwick {
    int n;
    vector<num_t> bit;

    void init(int s) {
        n = s;
        bit.assign(n + 1, num_t(0));
    }

    void update(int pos, num_t v) {
        int i = pos + 1;
        while (i <= n) {
            bit[i] = max(bit[i], v);
            i += i & -i;
        }
    }

    num_t query(int pos) {
        if (pos < 0) return num_t(0);
        num_t res = num_t(0);
        int i = pos + 1;
        while (i > 0) {
            res = max(res, bit[i]);
            i -= i & -i;
        }
        return res;
    }
};
