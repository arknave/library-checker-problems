#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    assert(ll(n) * q <= TEN(8));
    struct S {
        ll l, r, a, b;
    };
    V<S> segments;
    for (int i = 0; i < n; i++) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        segments.push_back(S{l, r, a, b});
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            // add
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            segments.push_back(S{l, r, a, b});
        } else {
            ll x;
            cin >> x;
            constexpr ll INF = 3 * TEN(18);
            ll ans = INF;
            for (auto s : segments) {
                if (s.l <= x && x < s.r) {
                    ans = min(ans, s.a * x + s.b);
                }
            }
            cout << (ans == INF ? "INFINITY" : to_string(ans)) << "\n";
        }
    }
    return 0;
}