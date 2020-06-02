#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
      vector<int> res;
      multiset<int> ms;
      if (nums1.size() > nums2.size()) {
        for (int i = 0; i < nums2.size(); i++) {
          ms.insert(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++) {
          if (ms.count(nums1[i]) > 0) {
            res.push_back(nums1[i]);
            ms.erase(ms.find(nums1[i]));
          }
        } 
      } else {
        for (int i = 0; i < nums1.size(); i++) {
          ms.insert(nums1[i]);
        }

        for(int i = 0; i < nums2.size(); i++) {
          if (ms.count(nums2[i]) > 0) {
            res.push_back(nums2[i]);
            ms.erase(ms.find(nums2[i]));
          }
        }
      }
      return res;
    }
};


int main() {
  multiset<int> ms;
  ms.insert(0);
  ms.insert(0);
  cout << ms.count(0) << endl;
  auto i = ms.find(0);
  ms.erase(i);
  cout << ms.count(0) << endl;
  return 0;
}
