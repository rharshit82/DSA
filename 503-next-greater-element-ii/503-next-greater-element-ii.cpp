class Solution {
public:
    // Loop once, we can get the Next Greater Number of a normal array.
    // Loop twice, we can get the Next Greater Number of a circular array
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=2*n-1; i>=0; i--){
            int num = nums[i%n];
            while(!st.empty() and st.top()<= num) st.pop();
            if(!st.empty()) res[i%n]=st.top();
            st.push(num);
        }
        return res;
    }
};