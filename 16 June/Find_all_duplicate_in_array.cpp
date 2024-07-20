/**
* APPROACH:
*   The idea behind this approach is that when we mark an element as visited by negating its value, 
*   we can detect the duplicate by checking if the element at the marked index is already negative.
* Time Complexity:
*   This approach has a time complexity of O(n).
* Space Complexity:
*   This approach has a space complexity of O(1).
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
     vector<int>res;
     for(int i=0; i<nums.size(); i++){
        nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        if(nums[abs(nums[i])-1] > 0){
            res.push_back(abs(nums[i]));
        }
     }
    return res;
    }
};