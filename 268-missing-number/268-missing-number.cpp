class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor=0;
        for(int i=0; i<nums.size(); i++){
            Xor=Xor^nums[i];
            Xor=Xor^(i+1);
        }
        return Xor;
    }
};