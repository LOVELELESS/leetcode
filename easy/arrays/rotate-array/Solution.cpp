#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; count < nums.size(); i++) {
            int currIndx = i;
            int currNum = nums[currIndx];
            int startingIndx = i;
            while (true) {
                int resIndx = (currIndx + k) % nums.size();
                int tmp = nums[resIndx];
                nums[resIndx] = currNum;
                currNum = tmp;
                currIndx = resIndx;
                count++;
                if (currIndx == startingIndx) {
                    break;
                }
            }
        }
    }
};
