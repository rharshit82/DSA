class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> result;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '+' or s[i] == '-' or s[i] == '*'){
                vector<int> inp1 = diffWaysToCompute(s.substr(0,i));
                vector<int> inp2 = diffWaysToCompute(s.substr(i+1,n-1));
                for(auto v1 : inp1){
                    for(auto v2: inp2){
                         if(s[i] == '+'){
                                result.push_back(v1+v2);
                            }
                         else if(s[i] == '-'){
                                result.push_back(v1-v2);
                            }
                         else{
                                result.push_back(v1*v2);
                            }
                    }
                }
            }
        }
        if(result.size()==0){
            result.push_back(atoi(s.c_str()));
        }
        return result;
    }
};