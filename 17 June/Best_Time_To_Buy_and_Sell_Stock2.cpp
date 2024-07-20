class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j = 0,ans = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[j] < prices[i]){
                ans += (prices[i] - prices[j]); 
            }
            j  = i;
        }
    return ans;
    }
};