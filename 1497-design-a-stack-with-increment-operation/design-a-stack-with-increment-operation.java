class CustomStack {
    int[] st;
    int curr;
    public CustomStack(int maxSize) {
        st = new int[maxSize];
        curr = -1;
    }
    
    public void push(int x) {
        if(curr +1 < st.length){
            curr++;
            st[curr] = x;
        }
    }
    
    public int pop() {
        if(curr == -1) return -1;
        int ele = st[curr];
        curr--;
        return ele;
    }
    
    public void increment(int k, int val) {
        for(int i=0; i<Math.min(st.length, k); i++){
            st[i] += val;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */