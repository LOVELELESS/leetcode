class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0) {
            return {};
        } else if (numRows == 1) {
            return {{1}};
        }
        vector<vector<int>> res = generate(numRows - 1);
        vector<int> last = res[numRows - 2];
        vector<int> v;
        v.push_back(1);
        int prev = last[0];
        for (int i = 1; i < numRows - 1; i++) {
            v.push_back(prev + last[i]);
            prev = last[i];
        }
        v.push_back(1);
        res.push_back(v);
        return res;
    }
};
