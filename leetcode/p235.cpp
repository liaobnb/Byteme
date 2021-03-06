#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Accepted
  // Recusive approach
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val && q->val < root->val)
      return lowestCommonAncestor(root->left, p, q);
    if (q->val > root && q->val > root->val)
      return lowestCommonAncestor(root->right, p, q);
    return root;
  }

  // Iterative approach
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *cur = root;
    while (true) {
      if (p->val < cur->val && q->val < cur->val)
        cur = cur->left;
      else if (p->val > cur->val && q->val > cur->val)
        cur = cur->right;
      else return cur;
    }
  }
};

int main() {
  return 0;
}
