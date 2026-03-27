// maximum hull, for minimum do addLine(-m, -c) and -query(x)
struct Line {
    long long m, c; 
    mutable long long p; 

    bool operator<(const Line& o) const { return m < o.m; }
    bool operator<(long long x) const { return p < x; }
};

struct convex_hull : multiset<Line, less<>> {
    static const long long INF = LLONG_MAX;

    long long div(long long a, long long b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = INF; return false; }
        if (x->m == y->m) x->p = x->c > y->c ? INF : -INF;
        else x->p = div(y->c - x->c, x->m - y->m);
        return x->p >= y->p;
    }

    void addLine(long long m, long long c) {
        auto z = insert({m, c, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }

    long long query(long long x) {
        if (empty()) return 0; 
        auto l = *lower_bound(x);
        return l.m * x + l.c;
    }

    void clear() {
        multiset::clear();
    }
};