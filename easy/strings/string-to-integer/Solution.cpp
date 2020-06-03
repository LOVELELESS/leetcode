class Solution {
public:
    int myAtoi(string str) {
        vector<char> s;
        bool isNeg = false;
        
        int start = 0;
        if (str[start] != ' ' && !isDigit(str[start]) && str[start] != '+' && str[start] != '-') {
            return 0;
        }
        
        while (str[start] == ' ') {
            start++;
            if (start == str.size()) {
                return 0;
            }
        }
        
        if (str[start] == '+') {
            start++;
        } else if (str[start] == '-') {
            isNeg = true;
            start++;
        }
        
        for (int i = start; i < str.size(); i++) {
            char c = str[i];
            if (isDigit(c)) {
                s.push_back(c);
            } else {
                break;
            }
        }
        
        if (s.size() == 0) {
            return 0;
        }
        
        if (isNeg) {
            s.insert(s.begin(), '-');
        }
        
        string st(s.begin(), s.end());
        try {
            return stoi(st);
        } catch(out_of_range e) {
            return isNeg ? INT_MIN : INT_MAX;
        }
    }
    
    bool isDigit(char c) {
        int i = c;
        return ((i >= 48) && (i <= 57));
    }
};
