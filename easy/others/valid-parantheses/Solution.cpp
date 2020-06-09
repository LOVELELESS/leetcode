class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int size = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
                size++;
                continue;
            }
            
            if (size == 0) {
                return false;
            }
            char top = stk.top();
            
            switch (c) {
                case ')':
                    if (top == '(') {
                        stk.pop();
                        size--;
                    } else {
                        return false;
                    }
                    break;
                case ']':
                     if (top == '[') {
                        stk.pop();
                        size--;
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (top == '{') {
                        stk.pop();
                        size--;
                    } else {
                        return false;
                    }
                    break;
            }
        }
        return size == 0;
    }
};
