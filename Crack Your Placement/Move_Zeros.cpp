/*
* APPROACH 1:
    A brute force approach to find zero and swap it with next non zero 
    element to it.
* Time Complexity:
    This approach has a time complexity of O(n^2).
* Space Complexity:
    This approach has a space complexity of O(1).

* APPROACH 2 (Optimized):
    Moves all non-zero elements to the beginning of the array,
    then fill the rest of the array with zeros.

* Time Complexity:
    This approach has a time complexity of O(n).
* Space Complexity:
    This approach has a space complexity of O(1).
*/

//Using 2nd Approach:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[last] = nums[i];
                last++;
            }
        }
        for(int i=last; i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};
