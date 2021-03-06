#include <bits/stdc++.h>
using namespace std;

// Given two 1d vectors, implement an iterator to return their elements alternately.
// For example, given two 1d vectors:
// v1 = [1, 2]
// v2 = [3, 4, 5, 6]
// By calling next repeatedly until hasNext returns false, 
// the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
// Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
// 

class ZigzagIterator {
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    a[0] = v1.begin(); a[1] = v1.end()-1;
    b[0] = v2.begin(); b[1] = v2.end()-1;
    flag = 0;
  }

  int next() {
    if (a[0] > a[1]) flag = 1;
    if (b[0] > b[1]) flag = 0;
    int t;
    if (flag == 0) {
      t = *a[0];
      a[0]++;
    } else {
      t = *b[0];
      b[0]++;
    }
    flag = 1 - flag;
    return t;
  }

  bool hasNext() {
    return (a[0] <= a[1] || b[0] <= b[1]);
  }

private:
  int flag;
  vector<int>::iterator a[2], b[2];
};

int main() {
  return 0;
}
