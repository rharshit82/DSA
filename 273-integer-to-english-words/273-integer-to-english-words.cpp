class Solution {
public:
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string findRes(int num){
        if(num>=1000000000) return findRes(num/1000000000) + " Billion" + findRes(num - (num/1000000000)*1000000000);
        if(num>=1000000) return findRes(num/1000000) + " Million" + findRes(num - (num/1000000)*1000000);
        if(num>=1000) return findRes(num/1000) + " Thousand" + findRes(num - (num/1000)*1000);
        if(num>=100) return findRes(num/100) + " Hundred" + findRes(num - (num/100)*100);
        if(num>=20) return " "+ (tens[num/10]) + findRes(num - (num/10)*10);
        if(num>=1) return " "+ (digits[num]);
        return "";
    }
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        return findRes(num).substr(1);
    }
};