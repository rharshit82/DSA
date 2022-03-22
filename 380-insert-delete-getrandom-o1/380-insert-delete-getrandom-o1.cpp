class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            nums.push_back(val);
            mp[val]=nums.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            //Putting Last element to found Element
            auto it = mp.find(val);
            nums[it->second]=nums.back();
            nums.pop_back();
            mp[nums[it->second]]=it->second; //Update last index value to current index
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
    private:
    unordered_map<int,int> mp;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */