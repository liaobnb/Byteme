#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // count sorting
  int arrayPairSum(vector<int>& a) {
    int ret = 0;
    bool flag = true;
    array<int, 20001> count{0};
    for (int i=0; i<a.size(); ++i)
      ++count[ a[i] + 10000 ];
    // already sorted
    // test output
    for (int i=0; i<20001; ++i)
       if (count[i]>0) cout << " " << i - 10000 << " ";
    cout << endl;

    for (int i=0; i<20001; ++i) {
      if (flag && count[i]) {
        ret += (i-10000);
        flag = false;
      }else if (count[i] && !flag)
        flag = true;
    }
    return ret;
  }
  //
  int arrayPairSum1(vector<int>& a) {
     sort(a.begin(), a.end());
     int ret = 0;
     for (int i=0; i<a.size(); i+=2)
       ret += a[i];
     return ret;
  }
};

int main() {
  return 0;
}
