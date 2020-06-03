class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, int> hm;
        for (int i = 0; i < s.size(); i++) {
            if (hm.find(s[i]) != hm.end()) {
                hm[s[i]] += 1;
            } else {
                hm[s[i]] = 1;
            }
        }
        
        for (int i = 0; i < t.size(); i++) {
            if (hm.find(t[i]) != hm.end() && hm[t[i]] > 0) {
                hm[t[i]] -= 1;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
