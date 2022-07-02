class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        sort(H.begin(),H.end());
        sort(V.begin(),V.end());
        int hdiff = max(H[0],h-H.back());
        int vdiff = max(V[0],w-V.back());
        if(h>1){
            for(int i=1; i<H.size(); i++){
            hdiff = max(hdiff, H[i]-H[i-1]);
        }
        }
        
        if(w>1){
            for(int i=1; i<V.size(); i++){
            vdiff = max(vdiff, V[i]-V[i-1]);
            }
        }
        
        return (1LL * vdiff * hdiff)%1000000007;
    }
};