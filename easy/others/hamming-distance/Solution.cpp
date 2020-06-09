class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        return countOnes(z);
    }
    
    int countOnes(int z) {
        int res = 0;
        while (z != 0) {
            res += z % 2;
            z = z / 2;
        }
        return res;
    }
};
