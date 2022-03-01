class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if(a.first==b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
    };
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, myComp> pq;
        unordered_map<int,int> mp;
        for(auto ele: nums) mp[ele]++;
        for(auto ele: mp){
            pq.push({ele.second,ele.first});
        }
        vector<int> res;
        while(!pq.empty()){
            int temp=pq.top().first;
            while(temp--)
                res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};