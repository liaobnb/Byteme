// #include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
#include <functional>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

// #define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
// template <typename T>
// void _f(const char* name, T&& arg) {
//     cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//     const char* split = strchr(names + 1, ',');
//     cout.write(names, split - names) << ": " << arg << " |";
//     _f(split, args...);
// }

// double tick() {
//     static clock_t old;
//     clock_t now = clock();
//     double diff = 1.0 * (now - old);
//     diff /= CLOCKS_PER_SEC;
//     old = now;
//     return diff;
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 1200;
int T, N;
int edges[maxn][maxn];
int dist[maxn];

void dijkstra(int src) {
    mst(dist, 0x3f);
    priority_queue<pii, vector<pii>, greater<pii> > dq;
    dq.push({src, 0});
    dist[src] = 0;

    while (sz(dq)) {
        pii cur = dq.top(); dq.pop();
        int u = cur.first;
        fori (i, 1, N + 1) {
            int v = i, w = edges[u][v];
            if (w != 0x3f3f3f3f && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                dq.push({v, dist[v]});
            }
        }
    }

    // par(dist, N + 1, 1);

    output(dist[N]);
}

void solve() {
    mst(edges, 0x3f);
    fori (i, 0, T) {
        int u, v, w; cin >> u >> v >> w;
        // In case repeated edges exist.
        edges[u][v] = min(edges[u][v], w);
        edges[v][u] = min(edges[v][u], w);
    }

    dijkstra(1);
}

int main() {
    while (cin >> T >> N) {
        solve();
    }
    return 0;
}

