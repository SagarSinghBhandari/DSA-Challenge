class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res = 0;
        for(int i =0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j]=='0'){
                    continue;
                }
                 res++;
                    queue<pair<int,int>> qu;
                    qu.push({i, j});
                    grid[i][j] = '0'; // Mark as visited
                    while(!qu.empty()) {
                        auto cur = qu.front();
                        qu.pop();
                        int curRow = cur.first;
                        int curCol = cur.second;
                        // Check up, down, left, right
                        if(curRow - 1 >= 0 && grid[curRow - 1][curCol] == '1') {
                            qu.push({curRow - 1, curCol});
                            grid[curRow - 1][curCol] = '0';
                        }
                        if(curRow + 1 < r && grid[curRow + 1][curCol] == '1') {
                            qu.push({curRow + 1, curCol});
                            grid[curRow + 1][curCol] = '0';
                        }
                        if(curCol - 1 >= 0 && grid[curRow][curCol - 1] == '1') {
                            qu.push({curRow, curCol - 1});
                            grid[curRow][curCol - 1] = '0';
                        }
                        if(curCol + 1 < c && grid[curRow][curCol + 1] == '1') {
                            qu.push({curRow, curCol + 1});
                            grid[curRow][curCol + 1] = '0';
                        } 
                }
            }
        }
        return res;
    }
};