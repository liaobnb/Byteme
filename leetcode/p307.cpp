#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
  NumArray(vector<int> aa) {
  n = sz(aa);
  bb = aa;
  bit.resize(n + 1);

  fori (i, 0, n)
    add(i, aa[i]);
  }
  
  int query(int ix) {
  int res = 0;
  ix += 1;
  while (ix > 0) {
    res += bit[ix];
    ix -= ix & (-ix);
  }
  return res;
  }

  void add(int ix, int inp) {
  ix += 1;
  while (ix <= n) {
    bit[ix] += inp;
    ix += ix & (-ix);
  }
  }
  
  void update(int ix, int inp) { 
  add(ix, inp - bb[ix]);
  bb[ix] = inp;
  } 

  int sumRange(int i, int j) {
  return query(j) - query(i-1); 
  }

  // Size of the input data.
  int n;
  vi bb;
  // Binary index tree array.
  vi bit;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

void test(vi aa) {
}

int main() {
   // test({1, 3, 5});
  test({7, 2, 7, 2, 0});
  return 0;
}
