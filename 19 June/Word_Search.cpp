class Solution {
    bool find(vector<vector<char>> &board, string word,int i,int j,int n,int m,int k){
        if(k== word.size()){
            return true;
        }
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[k]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        bool r1 = find(board,word,i+1,j,n,m,k+1);  //downward
        bool r2 = find(board,word,i,j+1,n,m,k+1);  //right side
        bool r3 = find(board,word,i-1,j,n,m,k+1);  //upward
        bool r4 = find(board,word,i,j-1,n,m,k+1);  //left side
        board[i][j] = temp;
        return r1 || r2 || r3 || r4;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
      int n = board.size();
      int m = board[0].size();
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              if(board[i][j]==word[0]){
                if(find(board,word,i,j,n,m,0)){
                    return true;
                }
              }
          }
      }
      return false;  
    }
};