class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int i=0,j=0,flag=0;
      vector<int>v;
      for(i=0; i<nums1.size(); i++){
          flag = 0;
          j=0;
          while(nums2[j]!=nums1[i]) j++;
          while(j<nums2.size()){
              if(nums1[i]<nums2[j]){
                  v.push_back(nums2[j]);
                  flag = 1;
                  break;
              }
               j++;
          }
      if(flag==0)
       v.push_back(-1);  
    }
    return v;
    }
};