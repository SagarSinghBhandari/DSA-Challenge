/*
* APPROACH 1:
    A brute force approach to find calculate profit by selling the stock on diffrent days
    and them return the maximum profit.  
    element to it.
* Time Complexity:
    This approach has a time complexity of O(n^2).
* Space Complexity:
    This approach has a space complexity of O(1).
APPROACH 2 (Optimized):
    Calculate the greatest nearest to right (GNR) to find the maximum value it can
    reach after the day of buying an then calculate the maximum profit.
* Time Complexity:
    This approach has a time complexity of O(n).
* Space Complexity:
    This approach has a space complexity of O(1).
*/


//Using 2nd Aproaach:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int curMax = prices[n-1];
        vector<int>GNR(n);
        for(int i=n-1; i>=0; i--){
           curMax = max(curMax,prices[i]);
           GNR[i] = curMax;
        }
    curMax = 0;
    for(int i= 0; i<n; i++){
        int d = GNR[i] - prices[i];
        curMax = max(curMax,d);
    }
        return curMax;
    }
};
