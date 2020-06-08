class Solution {
private:
    vector<int> nums;
    default_random_engine generator;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> v(nums.size(), 0);
        for (int i = 0; i < v.size(); i++) {
            v[i] = nums[i];
            int swp = rand(0, i);
            swap(v, i, swp);
        }
        return v;
    }
    
    int rand(int lo, int hi) {
        uniform_int_distribution<int> distribution(lo,hi);
        return distribution(generator);
    }
    
    void swap(vector<int> &v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
}; 

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
