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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        return checkRoot(root -> left, root -> right);
    }
    
    bool checkRoot(TreeNode *rootL, TreeNode *rootR) {
        if (rootL == nullptr && rootR == nullptr) {
            return true;
        }
        
        if ((rootL == nullptr && rootR) || 
            (rootL && rootR == nullptr) ||
            (rootL -> val != rootR -> val)) {
            return false;
        }
        
        return checkRoot(rootL -> left, rootR -> right) &&
            checkRoot(rootL -> right, rootR -> left);
    }
};
