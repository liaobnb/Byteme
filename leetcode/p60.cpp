#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Naive approach
  string getPermutation2(int n, int k) {
    if (k <= 0) return "";
    string s = "";
    for (int i=1; i<=n; ++i)
      s += ('0' + i);

    while (--k > 0) {
      next_permutation(s.begin(), s.end());
    }

    return s;
  }

  void bt(int k, int n, string ans, string& res) {
    if (ans.size() == n) {
      res = ans;
      return ;
    } else {
      for (int i = 1; i <= n; ++i) {
        if (find(ans.begin(), ans.end(), '0' + i) != ans.end()) continue;
        ans.push_back('0' + i);
        bt();
        ans.pop_back();
      }
    }
  }

  string getPermutation(int n, int k) {
    string res = "";
    bt(0, k, n, res);
    return res;
  }
};

int main() {
  return 0;
}
