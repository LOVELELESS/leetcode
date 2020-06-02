#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public: 
    int singleNumber(vector<int> &nums) {
      int res = 0;
      for (int i = 0; i < nums.size(); i++) {
        res = res ^ nums[i];
      }
      return res;
      /*
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i += 2) {
        int curr = nums[i];
        if (i == nums.size() - 1) {
          return curr;
        }

        int next = nums[i + 1];
        if (curr != next) { 
          return curr;
        }
      }
      return 0;
      */
    }

};
