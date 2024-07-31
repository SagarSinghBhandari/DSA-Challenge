class Solution {
public:
    int coinChangeHelper(vector<int>& coins, int amount, int start) {
        if(amount == 0)
            return 0;
        if(start == coins.size()) 
            return -1;
        if(amount < coins[start]) 
            return -1;

        int a = coinChangeHelper(coins, amount, start+1);
        int b = coinChangeHelper(coins, amount-coins[start], start);
        if(a >= 0 && b >= 0) 
            return min(a, 1+b);
        if(b >= 0) 
            return b+1;
        if(a >= 0) 
            return a;
        return -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return coinChangeHelper(coins, amount, 0);
    }
};