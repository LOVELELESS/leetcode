class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currSearchIndx = 1;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            if (nums[i] == 0) {
                // start searching for non-zero ele
                for (; currSearchIndx < nums.size(); currSearchIndx++) {
                    if (nums[currSearchIndx] != 0) {
                        break;
                    }
                }
                if (currSearchIndx == nums.size()) {
                    // no more non-zero ele
                    return;
                }
                swap(nums, i, currSearchIndx);
                currSearchIndx++;
            } else {
                currSearchIndx++;
            }
        }
    }
    
private:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
