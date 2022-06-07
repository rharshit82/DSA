class FindSumPairs {
public:
    map<int,int> mp1,mp2;
    vector<int> nums2;
    FindSumPairs(vector<int>& t1, vector<int>& t2) {
        nums2=t2;
         int n1=t1.size();
        int n2=t2.size();
         for(int i=0; i<n1; i++){
            mp1[t1[i]]++;
        }
        for(int i=0; i<n2; i++){
            mp2[t2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp2[nums2[index]]--;
        nums2[index]+=val;
        mp2[nums2[index]]++;
    }
    
    int count(int tot) {
        int res=0;
       
        for(auto it: mp1){
            if(mp2.find(tot-it.first)!=mp2.end()){
                res+=it.second * mp2[tot-it.first];
            }
        }
        
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */