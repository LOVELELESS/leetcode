// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;
        while (lo < hi) {
            int mid = ((hi - lo) / 2) + lo;
            if (isBadVersion(mid)) {
                // recurse on left
                hi = mid;
            } else {
                // recurse on right
                lo = mid + 1;
            }
        }
        return lo;
    }
};
