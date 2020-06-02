class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]].push_back(i);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int desired = target - curr;
            vector<int> res = um[desired];
            for (int j = 0; j < res.size(); j++) {
                if (res[j] != i) {
                    return {i, res[j]};
                }
            }
        }
        return {};
    }
};
