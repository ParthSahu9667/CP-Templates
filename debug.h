

#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << x;}
void __print(const char *x) {cout << x;}
void __print(const string &x) {cout << x;}
void __print(bool x) {cout << x;}
void debugpair(vector<pair<int, int>> v) {for (auto &it: v) cout << it.first << ' ' << it.second << '\n';}
void debugpair(set<pair<int, int>> v) {for (auto &it: v) cout << it.first << ' ' << it.second << '\n';}
void debugpair(set<pair<long long, long long>> v) {for (auto &it: v) cout << it.first << ' ' << it.second << '\n';}
void debugpair(vector<pair<long long, long long>> v) {for (int it = 0; it < v.size(); it++) cout << v[it].first << ' ' << v[it].second << '\n';}
void debug2d(vector<vector<int>> &v) {for (int i = 0; i < v.size(); i++) {for (auto &it: v[i]) {cout << it << ' ';} cout << '\n';}}
void debug2d(vector<string> &v) {for (int i = 0; i < v.size(); i++) {for (auto &it: v[i]) {cout << it << ' ';} cout << '\n';}}
void debug2d(vector<vector<long long>> &v) {for (int i = 0; i < v.size(); i++) {for (auto &it: v[i]) {cout << it << ' ';} cout << '\n';}}

template<typename T, typename V>
void __print(const pair<T, V> &x) {__print(x.first); cout << ' '; __print(x.second);}
template<typename T>
void __print(const T &x) {int f = 0; for (auto &i: x) cout << (f++ ? " " : ""), __print(i);}
void _print() {cout << '\n';}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << " "; _print(v...);}

#define debug(x...) cout << #x << ": "; _print(x)