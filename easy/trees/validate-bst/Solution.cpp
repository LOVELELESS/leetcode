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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode *root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        
        long rtVal = (long) (root -> val);
        if ((rtVal >= min) && (rtVal <= max)) {
            return isValidBST(root -> left, min, rtVal - 1) && 
                isValidBST(root -> right, rtVal + 1, max);
        }
        
        return false;
    }
};
