/*
* APPROACH 1:
    A brute force approach to find eery possible pairs formed using elements
    of the array and then simply check whoes sum is equal to target.
* Time Complexity:
    This approach has a time complexity of O(n^2).
* Space Complexity:
    This approach has a space complexity of O(1).

* APPROACH 2 (Optimized):
    Use map to store the elements of the array and their corresponding indices.
    For each element in the array, calculate the complement (target - element).
    If the complement exists in the map, it means we have found a pair that sums up to target.
* Time Complexity:
    This approach has a time complexity of O(n).
* Space Complexity:
    This approach has a space complexity of O(n).
*/

//Using 2nd Aproach:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }
        for(int i=0; i<n; i++){
            int comp = target - nums[i];
            auto x = mp.find(comp);
            if(x!=mp.end() && x->second!=i)
                return {i,x->second};
        }
        return {};
    }
};
