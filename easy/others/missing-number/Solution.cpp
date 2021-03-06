class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int expected = (n + 1) * n / 2;
        for (int i = 0; i < n; i++) {
            res += nums[i];
        }

        return expected - res;
    }
};
