#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findNumberOfLIS(vector<int>& aa) {
    int n, res, mx;
    n = sz(aa);
    res = 0;
    mx = 0;
    // dp[i].fi denotes the length of the LSP ending at the ith index.
    // dp[i].se dentoes the number of the LSP ending at the ith index.
    vpii dp(n, {1, 1});
    fori (i, 0, n) {
      fori (j, 0, i) {
      if (aa[j] < aa[i]) {
        if(dp[i].fi == dp[j].fi + 1)
        dp[i].se += dp[j].se;
        if (dp[i].fi < dp[j].fi + 1)
        dp[i] = {dp[j].fi + 1, dp[j].se};
      }
      }
      if (mx == dp[i].fi)
      res += dp[i].se;
      else if (mx < dp[i].fi) {
      mx = dp[i].fi;
      res = dp[i].se;
      }
    }
    return res;
  }
};

void test(vi aa) {
  Solution go;
  int r = go.findNumberOfLIS(aa);
  output(r);
}

int main() {
  test({1, 3, 5, 4, 7});
  test({2, 2, 2, 2, 2});
  return 0;
}
