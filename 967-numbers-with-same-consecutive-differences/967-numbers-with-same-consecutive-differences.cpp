class Solution {
public:
    void makeNumber(vector<int>&res, int n, int k, string& cur){
        if(n == 0){
            res.push_back(stoi(cur));
            return;
        }
        if(cur.size() == 0){
            for(int i=1; i<=9; i++){
                cur+=(i+'0');
                makeNumber(res, n-1, k, cur);
                cur.pop_back();
            }
            return;
        }
        if(((cur.back()-'0') + k) >=0 and ((cur.back()-'0') + k)<=9){
            cur+=((cur.back()-'0') + k)+'0';
            makeNumber(res,n-1, k, cur);
            cur.pop_back();
        }
        if(k==0) return;
        if(((cur.back()-'0') - k)>=0 and ((cur.back()-'0') - k)<=9){
           cur+=((cur.back()-'0') - k)+'0';
            makeNumber(res,n-1, k, cur);
            cur.pop_back();
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        string c = "";
        makeNumber(res, n, k, c);
        return res;
    }
};