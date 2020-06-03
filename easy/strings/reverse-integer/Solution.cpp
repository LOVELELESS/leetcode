#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int reverse(int x) {
      if (x > INT_MAX || x < INT_MIN) {
        return 0;
      }

      bool isNeg = x < 0;
      string s = to_string(x);  

      int lo, hi;
      if (x < 0) {
        lo = 1;
        hi = s.size() - 1;
      } else {
        lo = 0;
        hi = s.size() - 1;
      }

      while (lo < hi) {
        swap(s, lo, hi);
        lo++;
        hi--;
      }

      try {
        int res = stoi(s);
        if (isNeg) {
          if (res >= 0) {
            return 0; // overflow
          }
        } else {
          if (res < 0) {
            return 0; // overflow
          }
        }

        return res;
      } catch (exception e) {
        return 0;
      }
    }

    void swap(string &s, int i, int j) {
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }
};

int main() {
  //Solution solution;
  //int i = solution.reverse(-123);
  int i = 1534236469;
  bool b = i > INT_MAX;
  cout << i << endl;
  cout << b << endl;
  return 0;
}
