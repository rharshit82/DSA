class MyStack {
public:
    //2 Queues
    // Push
    //     Add x -> Q2
    //     Q1 -> Q2 (elemnt by elemnt)
    //     Swap(Q1,Q2)
    // Pop
    //     Remove the Top of Q1
    // Top
    //     Top of Q1
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int res = top();
        if(!q1.empty()) q1.pop();
        return res;
    }
    
    int top() {
        if(!q1.empty()) return q1.front();
        return -1;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */