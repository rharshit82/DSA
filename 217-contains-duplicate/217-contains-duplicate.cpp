class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto ele:nums){
            st.insert(ele);
        }
        return st.size()!=nums.size();
    }
};