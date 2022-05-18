class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        int i=n-1,j=m-1;
        string res="";
        int carry=0;
        while(i>=0 and j>=0){
            int sum = (a[i]-'0' )+ (b[j]-'0' ) + carry;
            if(sum==0 or sum==1){
                res+=sum+'0';
                carry=0;
            }
            if(sum==2){
                res+='0';
                carry=1;
            }
            if(sum==3){
                res+='1';
                carry=1;
            }
            i--;
            j--;
        }
        while(i>=0){
            int sum = (a[i]-'0' ) + carry;
            if(sum==0 or sum==1){
                res+=sum+'0';
                carry=0;
            }
            if(sum==2){
                res+='0';
                carry=1;
            }
            if(sum==3){
                res+='1';
                carry=1;
            }
            i--;
        }
        while(j>=0){
            int sum = (b[j]-'0' ) + carry;
            if(sum==0 or sum==1){
                res+=sum+'0';
                carry=0;
            }
            if(sum==2){
                res+='0';
                carry=1;
            }
            if(sum==3){
                res+='1';
                carry=1;
            }
            j--;
        }
        if(carry) res+=carry+'0';
        reverse(res.begin(),res.end());
        return res;
    }
};