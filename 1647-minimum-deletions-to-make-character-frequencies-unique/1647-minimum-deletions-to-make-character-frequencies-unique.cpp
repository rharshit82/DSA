class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        map<char,int> mp;
        for(auto e: s){
            mp[e]++;
        }
        priority_queue<int> pq;
        for(auto k: mp){
            pq.push(k.second);
        }
        
        int res=0;
        while(pq.size()>1){
            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            if(val2==val1){
                val1--;
                res++;
                if(val1==0) continue;
                pq.push(val1);
            }
            
        }
        return res;
        // 1 0 2 3
        
// "bbcebab"
//     b-> 4
//     // c-> 1
//     e->1
//     a->1
    }
};