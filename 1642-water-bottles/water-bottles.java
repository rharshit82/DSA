class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        res+= numBottles;
        int empty = numBottles, nonEmpty = 0;
        while(empty >= numExchange || nonEmpty > 0){
            if(nonEmpty > 0){
                res+= nonEmpty;
                empty+= nonEmpty;
                nonEmpty = 0;
            }

            if(empty > 0){
                nonEmpty+= empty/numExchange;
                empty = empty%numExchange;
            }

        }
        res+= nonEmpty;
        return res;
    }
}
// 



// 15 -> 
//  9 3 3/3 1 
// 9 
// 3 
// 9 9/3 3 0 
// 15

// 3

// 
// 15 4
// a/b a%b
// 




// 15
// 12 -> 3
// 6 -> 