//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    vector<int>copy;
        unordered_map<int ,int>mp;
        for(int i=0;i<n;i++){
            mp.insert({nums[i],i});
            copy.push_back(nums[i]);
        }
        sort(copy.begin(),copy.end());
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=copy[i]){
                int i1=mp[copy[i]];
                int i2=mp[nums[i]];
                swap(nums[i1],nums[i2]);
                mp[nums[i1]]=i1;
                mp[nums[i2]]=i2;
                cnt++;
            }
        }
      return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends