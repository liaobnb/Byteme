#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int dp[N][N];

class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int a, b;
    mst(dp, 0);
    fora (s, strs) {
      a = b = 0;
      fora (c, s)
      if (c == '0') ++a;
      else if (c == '1') ++b;

      ford (i, m, -1)
        ford (j, n, -1) {
          if (i >= a && j >= b)
          dp[i][j] = max(dp[i][j], dp[i-a][j-b] + 1);
        }
    }
    return dp[m][n];
  }
};

void test(vstr inp, int m, int n) {
  Solution go;
  int r = go.findMaxForm(inp, m, n);
  output(r);
}

int main() {
  test({"10", "0001", "111001", "1", "0"}, 5, 3);
  test({"10", "0", "1"}, 1, 1);
  return 0;
}
