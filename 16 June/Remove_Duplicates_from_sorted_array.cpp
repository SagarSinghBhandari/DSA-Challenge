/*
* APPROACH 1: 
    We can use unordered set that implicitly maintains uniqueness of the 
    values in the array.
 Time Complexity: 
    O(n)
 Space Complexity:
    O(n)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
        nums.clear();
        for(auto x: set){
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        return nums.size();
    }
};

/*
* APPROACH 2:
*   We can use two pointers, one to iterate through the array and another to keep track of the unique elements.
*   We swap the elements at the current index and the unique index, then increment both indices.
* Time Complexity:
*   O(n)
* Space Complexity:
*   O(1);
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int unique = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i]!= nums[unique - 1]) {
                nums[unique++] = nums[i];
            }
        }
        return unique;
    }
};
    