#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(val) cout << (val) << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (val) << endl
#define pvi(x) cout << #x << ": "; fora(a, x) cout << a << " "; cout << endl
#define par(x, n) cout<< #x << ": "; fori(a, 0, n) cout<<x[a]<<" "; cout <<endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
  vpii aa;
  int n; cin >> n >> ws;
  int base = 1;
  fori (i, 1, n + 1) {
    int x; cin >> x;
    aa.pb({base, base + x - 1});
    base = base + x;
  }

  int m; cin >> m;
  fori (i, 0, m) {
    int x; cin >> x;
    int lo = 0, hi = sz(aa) - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (aa[mid].first <= x && x <= aa[mid].second) {
        output(mid + 1);
        break;
      } else if (x < aa[mid].first) hi = mid - 1;
      else if (x > aa[mid].second) lo = mid + 1;
    } 
  }

  return 0;
}
