class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res=0;
        int coveredTillNow=-1;
        int left=-1;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(coveredTillNow<intervals[i][1] and left<intervals[i][0]){
                left=intervals[i][0];
                res++;
            }
            coveredTillNow=max(coveredTillNow,intervals[i][1]);
        }
        return res;
    }
};