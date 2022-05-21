class StockSpanner {
public:
    unordered_map<int,int> mp;
    stack<pair<int,int>> st;
    vector<int> arr;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() and st.top().first<=price) st.pop();
        if(st.empty()) {
            st.push({price,i++});
            return i;
        } 
        int res = i-st.top().second;
        st.push({price,i++});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */