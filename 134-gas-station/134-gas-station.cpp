class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gc=0, cc = 0;
        for(int i=0; i<n; i++){
            gc+=gas[i];
        }
        for(int i=0; i<n; i++){
            cc+=cost[i];
        }
        if(gc<cc) return -1;
        int diff = 0;
        int start = 0;
        for(int i=0; i<n; i++){
            diff+=gas[i] - cost[i];
            if(diff<0){
                diff= 0;
                start = i+1;
            }
        }
        return start;
    }
};