class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]){
            return image;
        }
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
    void dfs(vector<vector<int>>&image,int currow,int curcol,int initialColor, int givenColor){
        int n = image.size();
        int m = image[0].size();
        if(currow<0 || curcol<0 || currow >= n || curcol >= m){
            return;
        }
        if(image[currow][curcol]!=initialColor){
            return;
        }

        image[currow][curcol] = givenColor;
        dfs(image,currow + 1, curcol,initialColor,givenColor);
        dfs(image,currow - 1, curcol ,initialColor,givenColor);
        dfs(image,currow, curcol + 1 ,initialColor,givenColor);
        dfs(image,currow, curcol-1 ,initialColor,givenColor);
    }
};