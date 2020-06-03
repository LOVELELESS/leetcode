class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int indx = 0;
        string s = "";
        if (strs.size() == 0) {
            return s;
        }
        
        int size = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            size = min(size, (int) strs[i].size());
        }
        
        while (indx < size) {
            char c = strs[0][indx];
            for (int i = 1; i < strs.size(); i++) {
                if (c != strs[i][indx]) {
                    return s;
                }
            }
            s.push_back(c);
            indx++;
        }
        return s;
    }
};
