#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>   // std:string std:stoi
#include <queue>
#include <deque>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// dfs approach
vector<vector<int>> res;
void dfs(TreeNode* root, int level) {
    if (!root) return;
    if (level == res.size()) {
        res.push_back(vector<int>());
    }
    res[level].push_back(root->val);
    dfs(root->left, level+1);
    dfs(root->right, level+1);
}
// another approach
// res[height-i] = queue[i]

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    dfs(root, 0);
    return vector<vector<int>> (res.rbegin(), res.rend());
}

int main(int argc, char** argv) {
    return 0;
}