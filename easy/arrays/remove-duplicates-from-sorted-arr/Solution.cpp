#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // Search for next indx s.t.
    // nums[next indx] > nums[curr idx]
    // resume next iteration from (next indx + 1)
    // return when reach end of arr
    // O(n)
    int removeDuplicates(vector<int> &nums) {
      int nextIndx = 1;
      for (int i = 1; i < nums.size(); i++) {
        int curr = nums[i - 1];
        while (nextIndx < nums.size() &&
            nums[nextIndx] <= curr) {
          nextIndx++;
        }

        if (nextIndx == nums.size()) {
          return i;
        }
        swap(nums, nextIndx, i);
        nextIndx++;
      }
      return nums.size();
    }

    void swap(vector<int> &nums, int i, int j) {
      //cout << "swapping " << nums[i] << " with " << nums[j] << '\n';
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }
};

void printArr(vector<int> &arr, int n) {
  cout << '[';
  for (int i = 0; i < n; i++) {
    cout << ' ' << arr[i] << ' ';
  }
  cout << "]\n";
}

int main() {
  int size;
  cin >> size;
  vector<int> v;
  for (int i = 0; i < size; i++) {
    int ele;
    cin >> ele;
    v.push_back(ele);
  }
  //printArr(v, size);
  Solution solution;
  int ans = solution.removeDuplicates(v);
  //printArr(v, ans);
  cout << ans;
  return 0;
}
