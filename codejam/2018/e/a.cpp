#include<bits/stdc++.h>
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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve(int t) {
  int n, k; cin >> n >> k;
  vi aa(n, 0);
  int mx = 0;
  fori (i, 0, n) {
    cin >> aa[i];
    mx = max(mx, aa[i]);
  }

  sort(all(aa)); 

  ll ret = 0; 
  int s = 0;
  fori (i, 1, mx + 1) {
    bool ok = 0;
    for (int j = 0; j < k; ) {
      if (s < n) {
        if (aa[s++] >= i) {
          ++ret; ++j;
        }
      } else {
        ok = 1; break;
      }
    }
    if (ok) break;
  }

  output(t, ret);

}

int main() {
 
  int t; cin >> t >> ws;
  fori (i, 1, t + 1) {
    solve(i);
  }

  return 0;
}

