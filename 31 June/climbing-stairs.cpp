class Solution {
public:
    int dp[1001];
    int helper(int n, int i){
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int l = helper(n,i+1);
        int r = helper(n, i+2);
        return dp[i] = l+r;
    }
    int climbStairs(int n){
        memset(dp,-1,sizeof(dp));
        return helper(n,0);
    }
};