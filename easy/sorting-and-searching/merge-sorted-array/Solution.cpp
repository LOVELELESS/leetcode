class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int firstTail = m - 1;
        int secondTail = n - 1;
        int currTail = m + n - 1;
        
        for (; (currTail >= 0 && firstTail >= 0 && secondTail >= 0); currTail--) {
            int fVal = nums1[firstTail];
            int sVal = nums2[secondTail];
            if (fVal < sVal) {
                nums1[currTail] = sVal;
                secondTail--;
            } else {
                nums1[currTail] = fVal;
                firstTail--;
            }
        }
        
        while (firstTail >= 0) {
            nums1[currTail] = nums1[firstTail];
            firstTail--;
            currTail--;
        }
        
        while (secondTail >= 0) {
            nums1[currTail] = nums2[secondTail];
            secondTail--;
            currTail--;
        }
        
        /*
        vector<int> v;
        for (int i = 0; i < m; i++) {
            v.push_back(nums1[i]);
        }
        
        int fIndx = 0;
        int sIndx = 0;
        int currIndx = 0;
        
        while (fIndx < m && sIndx < n) {
            int fVal = v[fIndx];
            int sVal = nums2[sIndx];
            if (fVal < sVal) {
                nums1[currIndx] = fVal;
                fIndx++;
            } else {
                nums1[currIndx] = sVal;
                sIndx++;
            }
            currIndx++;
        }
        
        while (fIndx < m) {
            nums1[currIndx] = v[fIndx];
            fIndx++;
            currIndx++;
        }
        
        while (sIndx < n) {
            nums1[currIndx] = nums2[sIndx];
            sIndx++;
            currIndx++;
        }
        */
    }
};
