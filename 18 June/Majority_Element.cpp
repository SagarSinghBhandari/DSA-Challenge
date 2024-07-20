class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int ans = 0,n = nums.size();
      unordered_set<int>s1(nums.begin(),nums.end());  
      unordered_multiset<int>s2(nums.begin(),nums.end());
      for(auto x: s1){
        if(s2.count(x) > (n/2))             
            ans = x;
      }
      return ans;
    }
};