/**
 * APPROACH 1:
 *  A simple two pointer approach is used.
 *  Maintain a left and a right pointer and capacity of the bars will be the 
 *  bar having minimum height among two (left and right) multiplied by 
 *  distance between them.  
 * Time complexity:
 *  O(n) [Since we are traversing the array only once].
 * Space Complexity:
 *  O(1) [Constant space used].
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0,n = height.size();
        int i=0, j=n-1,cap = 0;
        while(i<j){
            if(height[i] < height[j]){
                cap = height[i]*(j-i);
                i++;
            }
            else{
                cap = height[j]*(j-i);
                j--;
            }
            ans = max(ans,cap);
        }
        return ans;
    }
};