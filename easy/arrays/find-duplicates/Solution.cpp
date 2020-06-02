#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> us;
      for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i];
        if (us.count(curr) > 0) {
          return true;
        } else {
          us.insert(curr);
        }
      }
      return false;
    }
};
