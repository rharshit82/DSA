class MinStack {
public:
    MinStack() {
        
    }
    stack<int> st;
    stack<int> minEles;
    void push(int val) {
        st.push(val);
        if(minEles.empty() or getMin()>=val) minEles.push(val);
    }
    
    void pop() {
        if(!minEles.empty() and minEles.top() == st.top()) minEles.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minEles.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */