class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() and heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) prevSmaller[i]=0;
            else prevSmaller[i] = st.top()+1; //Add 1 for Boundary of Rectangle
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) nextSmaller[i]=n-1;
            else nextSmaller[i]=st.top()-1;
            st.push(i);
        }
        int res=0;
        for(int i=0; i<n; i++){
            res = max(res, (nextSmaller[i]-prevSmaller[i]+1)*heights[i]);
        }
        return res;
    }
};