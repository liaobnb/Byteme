#include <bits/stdc++.h>
using namespace std;

vector<double> averageOfLevels(TreeNode* root) {
  vector<double> res;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    double sum = 0;
    int n = q.size();
    for (auto i=0; i<n; ++i) {
      TreeNode* x = q.front();
      q.pop();
      sum += x->val;
      if (x->left)
        q.push(x->left);
      if (x->right)
        q.push(x->right);
    }
    res.push_back(sum / n);
  }
  return res;
}
int main() {
  return 0;
}
