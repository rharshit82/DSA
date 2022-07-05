class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(auto ele: nums){
            st.insert(ele);
        }
        int res=0;
        int cur=1;
        for(auto ele: st){
            if(st.find(ele+1)!=st.end()){
                cur++;
            } else{
                cur=1;
            }
            res = max(res, cur);
        }
        return res;
    }
};