// #include <bits/stdc++.h>
#include <vector>
#include <cstring>
#include <iostream>
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
//   cout << fixed << name << ": " << arg << '\n';
// }

// template <typename T, typename... Args>
// void _f(const char* names, T&& arg, Args&&... args) {
//   const char* split = strchr(names + 1, ',');
//   cout.write(names, split - names) << ": " << arg << " |";
//   _f(split, args...);
// }

// double tick() {
//   static clock_t old;
//   clock_t now = clock();
//   double diff = 1.0 * (now - old);
//   diff /= CLOCKS_PER_SEC;
//   old = now;
//   return diff;
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

int n, k, r;
int visit[10];
vs aa;

void dfs(int i, int j, int k, int& r) {
  if (k == 0) {
    r++;
    // trace(r);
    return;
  }
  visit[j] = 1;
  fori (p, i + 1, n) {
    fori (q, 0, n) {
      if (!visit[q] && aa[p][q] == '#') {
        // trace(p, q);
        dfs(p, q, k - 1, r);
      }
    }
  }
  visit[j] = 0;
}

void solve() {
  aa.clear();
  mst(visit, 0);
  fori (i, 0, n) {
    string s; cin >> s;
    aa.pb(s);
  }
  // pvi(aa, 1);

  r = 0;
  fori (i, 0, n) {
    fori (j, 0, n) {
      if (aa[i][j] == '#') {
        // trace(i, j);
        dfs(i, j, k - 1, r);
      }
    }
  }
  output(r);
}

int main() {
  while (cin >> n >> k) {
    if (n == -1 && k == -1) break;
    solve();
  }
  return 0;
}

