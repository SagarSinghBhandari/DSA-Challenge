/*
* APPROACH:
    The idea behind this approach is that when we mark an element as visited by negating its value, 
    we can detect the duplicate by checking if the element at the marked index is already negative.
* Time Complexity:
    This approach has a time complexity of O(n).
* Space Complexity:
    This approach has a space complexity of O(1).
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res;
        for(int i=0; i<nums.size(); i++){
            nums[abs(nums[i])] = -nums[abs(nums[i])];
            if(nums[abs(nums[i])]>0)
                res = abs(nums[i]);
        }
        return res; 
    }
};
