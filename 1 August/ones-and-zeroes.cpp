class Solution {
public:
    int solve(vector<string>& strs, int m, int n,int i,vector<vector< vector<int>>>& dp){
        if(i==strs.size() || m<0 || n<0) 
            return 0;
        if(m==0 && n==0) 
            return 0;
        if(dp[i][m][n]!=-1) 
            return dp[i][m][n];

        int zeros = count(strs[i].begin(),strs[i].end(),'0');
        int ones = strs[i].length()-zeros;
        
        if(zeros<=m && ones<=n) 
            return dp[i][m][n] = max(solve(strs,m,n,i+1,dp) , solve(strs,m-zeros,n-ones,i+1,dp)+1);
        else 
            return dp[i][m][n] = solve(strs,m,n,i+1,dp);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector< vector<int> > > dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs,m,n,0,dp);      
    }
};