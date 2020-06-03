class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        
        if (haystack.size() < needle.size()) {
            return -1;
        }
        
        string s;
        unordered_map<string, int> hm;
        int i = 0;
        for (; i < needle.size(); i++) {
            s.push_back(haystack[i]);
        }
        
        hm[s] = 0;
        for (; i < haystack.size(); i++) {
            s.push_back(haystack[i]);
            s.erase(s.begin());
            if (hm.find(s) != hm.end()) {
                continue;
            } else {
                hm[s] = i - (needle.size() - 1);
            }
        }
        
        if (hm.find(needle) != hm.end()) {
            return hm[needle];
        }
        
        return -1;
        
    }
};
