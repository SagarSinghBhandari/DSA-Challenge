#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      // Use a set to store unique elements
        set<int> uniqueNums(nums.begin(), nums.end());
        // Copy the unique elements back into the original vector
        nums.assign(uniqueNums.begin(), uniqueNums.end());
        // Return the new length of the vector
        return nums.size();
      

    }   
};
int main(){
  
  vector<int> nums={3,3,3,3,3};
    Solution sol;  
    int newLength = sol.removeDuplicates(nums); 

    // Output the new length and the modified vector
    cout << "New length: " << newLength << endl;
    cout << "Modified vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}