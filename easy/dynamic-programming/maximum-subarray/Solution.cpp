class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int currSum = nums[0];
        int res = currSum;
        for (int i = 1; i < nums.size(); i++) {
            int nextSum = currSum + nums[i];
            currSum = max(nextSum, nums[i]);
            res = max(currSum, res);
        }
        return res;
    }
};
