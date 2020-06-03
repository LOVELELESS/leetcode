class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hm;
        for (int i = 0; i < s.size(); i++) {
            if (hm.find(s[i]) != hm.end()) {
                hm[s[i]] += 1;
            } else {
                hm[s[i]] = 1;
            }
        }
        
        for (int i = 0; i < s.size(); i++) {
            int c = hm[s[i]];
            if (c == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
