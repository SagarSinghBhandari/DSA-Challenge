class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if (i >= grid.size() || j >= grid[0].size())
            return INT_MAX;
        
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];
        
        int l = INT_MAX, r = INT_MAX;
        
        if (i < grid.size() - 1)
            l = grid[i][j] + helper(grid, i + 1, j, dp);
        
        if (j < grid[0].size() - 1)
            r = grid[i][j] + helper(grid, i, j + 1, dp);
        
        dp[i][j] = min(l, r);
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return helper(grid, 0, 0, dp);
    }
};
