// point update segment tree
template <typename num_t>
struct segtree {
    int n;
    vector<num_t> tree;

    void init(int s, vector<num_t>& arr) {
        n = s;
        tree.assign(4 * s, 0);
        init(0, 0, n - 1, arr);
    }

    num_t combine(int a, int b) {
        return max(a, b); // change function here
    }

    num_t init(int i, int l, int r, vector<num_t>& arr) {
        if (l == r) return tree[i] = arr[l];

        int mid = (l + r) / 2;
        num_t a = init(2 * i + 1, l, mid, arr);
        num_t b = init(2 * i + 2, mid + 1, r, arr);
        return tree[i] = combine(a, b);
    }

    void update(int pos, num_t v) {
        update(0, 0, n - 1, pos, v);
    }

    num_t update(int i, int tl, int tr, int pos, num_t v) {
        if (tl == tr) return tree[i] = v;

        int mid = (tl + tr) / 2;
        if (pos <= mid)
            tree[i] = combine(update(2 * i + 1, tl, mid, pos, v), tree[2 * i + 2]);
        else
            tree[i] = combine(tree[2 * i + 1], update(2 * i + 2, mid + 1, tr, pos, v));

        return tree[i];
    }
    
    num_t query(int l, int r) {
        if (l > r) return 0; // change return statement here as well
        return query(0, 0, n - 1, l, r);
    }

    num_t query(int i, int tl, int tr, int ql, int qr) {
        if (ql <= tl && tr <= qr) return tree[i];
        if (tr < ql || qr < tl) return 0; // change return statement here as well

        int mid = (tl + tr) / 2;
        num_t a = query(2 * i + 1, tl, mid, ql, qr);
        num_t b = query(2 * i + 2, mid + 1, tr, ql, qr);
        return combine(a, b);
    }
};

// lazy segmnent tree
template <typename num_t>
struct segtree {
    int n;
    vector<num_t> tree, lazy;

    void init(int s, vector<num_t>& arr) {
        n = s;
        tree.assign(4 * s, 0);
        lazy.assign(4 * s, 0);
        init(0, 0, n - 1, arr);
    }

    num_t combine(int a, int b) {
        return max(a, b); // change function here
    }

    num_t init(int i, int l, int r, vector<num_t>& arr) {
        if (l == r) return tree[i] = arr[l];

        int mid = (l + r) / 2;
        num_t a = init(2 * i + 1, l, mid, arr);
        num_t b = init(2 * i + 2, mid + 1, r, arr);
        return tree[i] = combine(a, b);
    }

    void push_down(int i) {
        if(lazy[i] != 0){
            tree[2 * i + 1] += lazy[i];
            tree[2 * i + 2] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
            lazy[i] = 0;
        }
    }

    void update(int pos, num_t v) {
        update(0, 0, n - 1, pos, v);
    }

    num_t update(int i, int tl, int tr, int pos, num_t v) {
        if (tl == tr) return tree[i] = v;

        push_down(i);
        int mid = (tl + tr) / 2;
        if (pos <= mid)
            tree[i] = combine(update(2 * i + 1, tl, mid, pos, v), tree[2 * i + 2]);
        else
            tree[i] = combine(tree[2 * i + 1], update(2 * i + 2, mid + 1, tr, pos, v));

        return tree[i];
    }

    void update(int l, int r, num_t v) {
        update_range(0, 0, n - 1, l, r, v);
    }

    num_t update_range(int i, int tl, int tr, int l, int r, num_t add) {
        if (l > tr || r < tl) return tree[i];
        if (l <= tl && tr <= r) {
            tree[i] += add;
            lazy[i] += add;
            return tree[i];
        }

        push_down(i);
        int mid = (tl + tr) / 2;
        num_t a = update_range(2 * i + 1, tl, mid, l, r, add);
        num_t b = update_range(2 * i + 2, mid + 1, tr, l, r, add);
        tree[i] = combine(a, b);
        return tree[i];
    }

    num_t query(int l, int r) {
        if (l > r) return 0; // change return statement here as well
        return query(0, 0, n - 1, l, r);
    }

    num_t query(int i, int tl, int tr, int ql, int qr) {
        if (ql <= tl && tr <= qr) return tree[i];
        if (tr < ql || qr < tl) return 0; // change return statement here as well

        push_down(i);
        int mid = (tl + tr) / 2;
        num_t a = query(2 * i + 1, tl, mid, ql, qr);
        num_t b = query(2 * i + 2, mid + 1, tr, ql, qr);
        return combine(a, b);
    }
};