/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            res.push_back(v);
            queue<TreeNode *> tmpQueue;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *next = q.front();
                q.pop();
                res[level].push_back(next -> val);
                if (next -> left != nullptr) {
                    tmpQueue.push(next -> left);
                }
                if (next -> right != nullptr) {
                    tmpQueue.push(next -> right);
                }
            }
            q = tmpQueue;
            level++;
        }
        return res;
    }
};
