class Solution {
public:
    void reverseString(vector<char>& s) {
        int lo = 0;
        int hi = s.size() - 1;
        while (lo < hi) {
            swap(s, lo, hi);
            lo++;
            hi--;
        }
    }
    
    void swap(vector<char> &s, int i, int j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    } 
};
