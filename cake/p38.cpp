#include<bits/stdc++.h>
using namespace std;

const int range_from  = 1;
const int range_to = 5;
std::random_device rd;
std::mt19937 generator(100);
std::uniform_int_distribution<int> dist(range_from, range_to);

int jran;
int uniform_random5() {
  // int jlo = 1, jhi = 5;
  // int im=6075, ia=106, ic=1283;
  // jran = (jran * ia + ic) % im;
  // int j = jlo + ((jhi - jlo + 1) * jran) / im;
  // return j;
  return dist(generator);
}

int uniform_random7() {

  while (true) {

    int r = uniform_random5() - 1;
    int c = uniform_random5() - 1;

    int p = r*5 + c + 1;

    if (p > 21) {
      continue;
    }

    return p%7 + 1;
  }

  // Never reach here.
  return -1;
}

int uniform_random7_1() {
  const int map[5][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 1, 2, 3},
    {4, 5, 6, 7, 1},
    {2, 3, 4, 5, 6},
    {7, 0, 0, 0 ,0}
  };

  while (true) {

    int r = uniform_random5() - 1;
    int c = uniform_random5() - 1;

    if (r == 4 && c > 0) {
      continue;
    }

    return map[r][c];
  }

  // Never reach here.
  return -1;
}

int main() {
  return 0;
}
