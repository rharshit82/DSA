class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() and heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) left[i] = 0;
            else left[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) right[i] = n-1;
            else right[i] = st.top()-1;
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res = max(res, (right[i] - left[i] + 1)*heights[i]);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> cols(m, 0);
        int res = 0;
        for(int i=0;i <n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    cols[j]++;
                } else{
                    cols[j] = 0;
                }
            }
            
            cout<<endl;
            res = max(res, largestRectangleArea(cols));
        }
        return res;
    }
};