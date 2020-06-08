class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        char prev = '0'; // dummy val
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            switch (c) {
                case 'I':
                    res += 1;
                    break;
                case 'V':
                    res += 5;
                    if (prev == 'I') {
                        res -= 2;
                    }
                    break;
                case 'X':
                    res += 10;
                    if (prev == 'I') {
                        res -= 2;
                    }
                    break;
                case 'L':
                    res += 50;
                    if (prev == 'X') {
                        res -= 20;
                    }
                    break;
                case 'C':
                    res += 100;
                    if (prev == 'X') {
                        res -= 20;
                    }
                    break;
                case 'D':
                    res += 500;
                    if (prev == 'C') {
                        res -= 200;
                    }
                    break;
                case 'M':
                    res += 1000;
                    if (prev == 'C') {
                        res -= 200;
                    }
                    break;
            }
            prev = c;
        }
        return res;
    }
};
