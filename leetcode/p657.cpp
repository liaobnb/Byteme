#include <bits/stdc++.h>
using namespace std;

bool judgeCircle(string moves) {
  int x = 0, y = 0;
  for (auto c: moves) {
    if (c == 'L')
      x -= 1;
    else if (c == 'R')
      x += 1;
    else if (c == 'U')
      y += 1;
    else if (c == 'D')
      y -= 1;
    else
      return false;
  }
  return x==0 && y==0;
}

int main() {
  return 0;
}
