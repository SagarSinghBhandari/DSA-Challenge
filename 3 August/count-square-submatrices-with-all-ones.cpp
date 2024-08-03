class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& matrix,int x,int y){
        if(x >= n || y >= m || matrix[x][y] == 0)
            return 0;
        if(dp[x][y] != -1)
            return dp[x][y];
        int right = solve(matrix,x,y+1);
        int down = solve(matrix,x+1,y);
        int diagonal = solve(matrix,x+1,y+1);
        return dp[x][y] =  min(right,min(down,diagonal)) + 1;
    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        int ans = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0; j < m;j++)
                ans += solve(matrix,i,j);
        return ans;
    }
};