class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        stack<int> st;
        int res=0;
        for(int i=0; i<=n; i++){
            while(!st.empty() and (i==n or heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                } else width = i-st.top()-1;
                res = max(res, (height* width));
            }
            st.push(i);
        }
        return res;
    }
};