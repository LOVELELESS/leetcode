#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k = k % nums.size();
      reverse(nums, 0, nums.size() - 1 - k);
      reverse(nums, nums.size() - k, nums.size() - 1);
      reverse(nums, 0, nums.size() - 1);
      /*
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
        */
    }
private:
    void reverse(vector<int> &nums, int i, int j) {
      while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
      }
    }

    void swap(vector<int> &nums, int i, int j) {
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
  int k;
  cin >> k;
  Solution solution;
  solution.rotate(v, k);
  printArr(v, v.size());
  return 0;
}
