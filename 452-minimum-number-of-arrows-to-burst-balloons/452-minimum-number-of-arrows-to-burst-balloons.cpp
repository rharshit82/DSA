class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }   
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        int res=1;
        sort(points.begin(),points.end(), comp);
        int back=points[0][1];
        for(int i=1;i<points.size();i++){
            if(back>=points[i][0]){
               continue;
            }else{
                res++;
                back=points[i][1];
            }
        }
        return res;
    }
    //[[10,16],[2,8],[1,6],[7,12]]
    //[1,6] [2,8] [7,12] [[10,16]
};