struct Min {
    Min *nextMin;
    int val;
    
    Min(int val, Min *nextMin) : val(val), nextMin(nextMin) {};
};

class MinStack {
public:
    Min *minObj;
    vector<int> v;
    int size;
    
    /** initialize your data structure here. */
    MinStack() {
        this->minObj = nullptr;
        this->v = vector<int>();
        this->size = 0;
    }
    
    void push(int x) {
        if (minObj == nullptr || x <= minObj->val) {
            this->minObj = new Min(x, minObj);
        }
        v.push_back(x);
        size++;
    }
    
    void pop() {
        int tail = top();
        if (tail == minObj->val) {
            this->minObj = this->minObj->nextMin;
        }
        v.erase(v.end() - 1, v.end());
        size--;
    }
    
    int top() {
        return v[this->size - 1];
    }
    
    int getMin() {
        return minObj->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
