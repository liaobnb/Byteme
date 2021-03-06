#include <bits/stdc++.h>
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

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int maxn = 320;
vvi gg;
vi aa;
int visit[maxn];
int dp[maxn];

int dfs(int u) {
  if (visit[u]) return dp[u];
  visit[u] = 1;
  int ret = 1;
  fori (i, 0, sz(gg[u])) {
    int v = gg[u][i] ? i : u;
    if (v != u && !visit[v]) {
      ret += dfs(v);
    } 
  }
  return dp[u] = ret;
}

class Solution {
public:
  int minMalwareSpread(vvi& g, vi& a) {
    gg = g; aa = a; 
    int ret = 0, ix;
    fora (a, aa) {
      mst(visit, 0);
      mst(dp, 0);
      int tmp = dfs(a);
      // trace(a, tmp);
      if (tmp > ret) {
        ret = tmp;
        ix = a;
      } else if (tmp == ret && a < ix) {
        ret = tmp;
        ix = a;
      }
    }
    return ix;
  }
};

void test(vvi g, vi a) {
  Solution go;
  int r = go.minMalwareSpread(g, a);
  output(r);
}

int main() {
 
  test({{1,1,0},{1,1,0},{0,0,1}}, {0, 1});
  test({{1,0,0},{0,1,0},{0,0,1}}, {0,2});
  test({{1,1,1},{1,1,1},{1,1,1}}, {1,2});
  test({{1,0,0,0},{0,1,0,0},{0,0,1,1},{0,0,1,1}}, {3,1});
  test({{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,1,0},{0,0,0,1,1,0},{0,0,0,0,0,1}}, {5,0});
  return 0;
}

