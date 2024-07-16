/**
 * APPROACH 1:
 *  Use min heap to maintain the order of the colors in the array.
 * Time complexity:
 *  O(nlogn) (O(nlogn) for inserting all colors in the heap and O(nlogn) to extract).
 * Space Complexity:
 *  O(n) (Extra Space of minheap).
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int , vector<int>, greater<int>>pq(nums.begin(),nums.end());
        nums.clear();
        while(!pq.empty()){
            int el = pq.top();
            pq.pop();
            nums.push_back(el);
        }
    }
};

/*
* APPROACH 2:
*   To use three-pointers left, mid and right.
*   By Swaping the values by comparing the mid pointer
*   with the left and right pointers.    
* Time complexity:
*   O(n) (Iterate through the array only once).
* Space Complexity:
*   O(1) (No extra space used).
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
