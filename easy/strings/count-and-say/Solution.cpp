#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string s = countAndSay(n - 1);
        int count = 1;
        char currChar = s[0];
        string res;
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            if (c == currChar) {
                count++;
            } else {
              //cout << count << endl;
                res.push_back('0' + count);
                res.push_back(currChar);
                count = 1;
                currChar = c;
            }
        }

        res.push_back('0' + count);
        //cout << res << endl;
        res.push_back(currChar);
        //cout << res << endl;
        return res;
    }
};

int main() {
  int a = min(5,4); 
  cout << a << endl;
  Solution solution;
  cout << solution.countAndSay(5) << endl;
  return 0;
}
