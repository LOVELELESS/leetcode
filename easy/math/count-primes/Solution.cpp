class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                res++;
            }
        }
        return res;
    }
    
    bool isPrime(int x) {
        int end = sqrt(x);
        for (int i = 2; i < end + 1; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
};
