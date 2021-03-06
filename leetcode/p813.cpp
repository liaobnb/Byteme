#include <bits/stdc++.h>
using namespace std;

// TODO
const int maxn = 105;
double dp[maxn][maxn];
class Solution {
public:
  double largestSumOfAverages(vector<int>& aa, int kk) {
    int n = sz(aa);
    aa.insert(aa.begin(), 0);
    dp[0][0] = 0;
    fori (k, 1, kk + 1) {
      fori (i, 1, n + 1) {
        double sum = 0;
        ford (j, i-1, -1) {
          sum += aa[j + 1];
          if (dp[j][k-1] == -1) continue;
          dp[i][k] = max(dp[i][k], dp[j][k-1] + sum / (i - j));
        }
      }
    }
    return dp[n][kk];
  }
};

void test(vi aa, int k) {
  Solution go;
  int r = go.largestSumOfAverages(aa, k);
  output(r);
}

int main() {
  test({9, 1, 2, 3, 9}, 3);
  return 0;
}
