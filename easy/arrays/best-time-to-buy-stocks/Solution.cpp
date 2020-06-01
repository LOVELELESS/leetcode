#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
      int lowIndx = 0;
      int res = 0;
      for (int i = 0; i < prices.size(); i++) {
        if (i == prices.size() - 1) {
          res += prices[i] - prices[lowIndx];
          break;
        }

        if (prices[i + 1] > prices[i]) {
          // on increasing subseq
        } else {
          // selloff
          res += prices[i] - prices[lowIndx];
          lowIndx = i + 1;
        }
      }
      return res;
    }
};

int main() {
  int size;
  cin >> size;
  vector<int> v;
  for (int i = 0; i < size; i++) {
    int ele;
    cin >> ele;
    v.push_back(ele);
  }
  Solution solution;
  cout << solution.maxProfit(v) << '\n';
  return 0;
}
