class Solution {
public:
    //Divide array into Two parts and minimize their Difference
    int lastStoneWeightII(vector<int>& stones) {
    /*
        To understand the problem, here is my intuition
        Forget about stones colliding, we have numbers and we should put + and - in the right places
        to get the minimum number in the end.

        What is the minimum number(at the end) possible?
        -> 0

        What should be the condition to get zero as the end result?
        -> let's say we have an array like [1,5,11,5] which can be split into two sets of equal sum
            set1 = {5, 5, 1} set2 = {11} sum of both these set is 11 so if we put all '-' to one of the set
            we get 0
            5 + 5 + 1 - 11

        How is that related to this problem?
        -> We are asked to minimize the end result, so if we are able to get two sets with minimum difference
           that should give us the result.

        How to get the sets?
        -> Our end result would be S1 - S2, which is sum of set1 - sum of set2. In the ideal case S1 == S2
           The Ideal case would be equal partition and also thing to notice here is, if it is ideal case then
            totalSum = 2 * S2 in other terms S2 = totalSum/2;
        -> We should try to choose elements whose sum is close to(ideally equal to) totalSum/2.
        -> S1 = totalSum - S2; 
        -> diff = S1 - S2; in other terms diff = totalSum - (2 * S2); diff should be our end result
    */

    int totalSum = accumulate(stones.begin(), stones.end(), 0);
    int target = totalSum/2, n = stones.size();

    vector<int> dp(target+1, 0);

    for(int stone: stones)
        for(int j = target; j >=stone; j--)
            dp[j] = max(dp[j] , stone + dp[j - stone]);

    return totalSum - 2 * dp[target];
}
};

