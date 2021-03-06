#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << endl
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
  int t = 6;
  vi aa(10, 0);
  fori (i, 1, t + 1) {
    int a; cin >> a;
    aa[a]++;
  }

  // pvi(aa, 1);

  int x, y, ok = 0;
  x = y = -1;
  fori (i, 1, 10) {
    if (aa[i] && aa[i] != 4) {
      if (x == -1) x = i;
      else if (y == -1) y = i;
      else {
        x = -1, y = -1;
        break;
      }
    }
    if (aa[i] >= 4) ok = 1;
  }

  // trace(x, y);
  
  string ret;
  if (ok == 0) ret = "Alien";
  else if (y == -1) ret = "Elephant";
  else if (x == y) ret = "Elephant";
  else ret = "Bear";

  output(ret);

  return 0;
}

