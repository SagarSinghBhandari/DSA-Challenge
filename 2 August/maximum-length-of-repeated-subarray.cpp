class Solution {
public:
    int findLength(vector<int>& S1, vector<int>& S2) {
        int dp[1001][1001];
        int n = S1.size(),m = S2.size();
        memset(dp,-1,sizeof(dp));
        int res = 0;
         for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (S1[i - 1] == S2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return res ;
    }
};