class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long res = 0;
        
        for (int i = 0; i < 31; i++) {
            res += n % 2;
            res = res * 2;
            n = n / 2;
        }
        
        res += n % 2;
        
        return res;
    }
};
