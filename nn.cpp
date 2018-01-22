#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x);
    printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
    printf("{\n");
    for (auto x:v)
    	printVector(x);
    printf("}\n");
}

int main(int argc, char** argv) {
  signed char c1 = -1; int i1 = (int)c1;
  unsigned char c2=-1; int i2 = (int)c2;
  int i3 = (int)(3*1.0/2*3);
  printf("%d %d %d\n", i1, i2, i3);

  enum color {x=0,y=3,b};
  printf("%d \n", b);

  #define ADD(arr) \
    do { \
      int i=0; \
      for (i=0; i<2; ++i) \
        ret += arr[i]; \
    } while(0)

    int a[2][2] = {1, 1};
    int i, ret=0;
    for (int i=0; i<2; ++i)
      ADD(a[i]);

    printf("%d\n", ret);

    struct {int a, b;}

    return 0;
}