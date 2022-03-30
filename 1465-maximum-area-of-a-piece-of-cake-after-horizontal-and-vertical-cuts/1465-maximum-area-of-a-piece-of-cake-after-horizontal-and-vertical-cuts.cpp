class Solution {
public:
    //Just know maximum height diff and maximum width diff after sorting. multiply them
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        int hS= hCuts.size();
        int vS= vCuts.size();
        sort(hCuts.begin(),hCuts.end());
        sort(vCuts.begin(),vCuts.end());
        int hDiff = max(hCuts[0]-0,h-hCuts[hS-1]);
        int vDiff = max(vCuts[0]-0,w-vCuts[vS-1]);

        if(hS>1){
            for(int i=1; i<hS; i++){
                hDiff = max(hDiff, hCuts[i]-hCuts[i-1]);
            }
        }
        if(vS>1){
            for(int i=1; i<vS; i++){
                vDiff = max(vDiff, vCuts[i]-vCuts[i-1]);
            }
        }
        long ans = 1L* hDiff * vDiff;
        return (int) (ans%1000000007);
    }
};