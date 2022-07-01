class Solution {
public:
    static bool mycomp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.rbegin(),boxTypes.rend(), mycomp);
        int res=0;
        for(int i=0; i<n and truckSize>0; i++){
            if(truckSize>=boxTypes[i][0]){
                res+=boxTypes[i][1]*boxTypes[i][0];
                truckSize-=boxTypes[i][0];
            } else{
                res+=(truckSize) * boxTypes[i][1];
                break;
            }
        }
        return res;
    }
};