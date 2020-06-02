class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int curr = digits[i];
            int res;
            if (i == digits.size() - 1) {
                res = curr + 1 + carry;
            } else {
                res = curr + carry;
            }
            
            carry = res / 10;
            digits[i] = res % 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
