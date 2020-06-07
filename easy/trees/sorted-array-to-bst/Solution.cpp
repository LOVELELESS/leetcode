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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBST(vector<int> &nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        } else if (lo == hi) {
            return new TreeNode(nums[lo]);
        }
        
        int mid = ((hi - lo) / 2) + lo;
        TreeNode *left = sortedArrayToBST(nums, lo, mid - 1);
        TreeNode *right = sortedArrayToBST(nums, mid + 1, hi);
        return new TreeNode(nums[mid], left, right);
    }
};
