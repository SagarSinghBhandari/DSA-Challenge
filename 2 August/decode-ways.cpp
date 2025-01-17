class Solution {
public:
    
    int decode(string& s, int i, int n,vector<int>&dp)
    {
        if(i < n && s[i] == '0') return 0;
        if(i >= n)
            return 1;
        
        int ways = 0;
        
        if(dp[i]!=-1)
            return dp[i];
        if(s[i] != '0') 
            ways = decode(s, i+1, n,dp);
            
        if(i+1 < n && ((s[i] == '1' && s[i+1] <= '9') || (s[i]=='2' && s[i+1] < '7')))
           ways += decode(s, i+2, n,dp);
           
        return dp[i] = ways;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return decode(s, 0, n,dp);
    }
};