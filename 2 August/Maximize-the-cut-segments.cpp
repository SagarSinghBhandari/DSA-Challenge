//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int helper(int n,int i, int x, int y, int z,vector<int>&dp){
        if(i==n){
            return 0;
        }
        if(i>n){
            return INT_MIN;
        }
        if(dp[i]!=-1)
            return dp[i];
        int l = 1 + helper(n,i + x,x,y,z,dp);
        int m = 1 + helper(n,i + y,x,y,z,dp);
        int r = 1 + helper(n,i + z,x,y,z,dp);
        return dp[i] = max(l,max(m,r));
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        int res = helper(n,0,x,y,z,dp);
        if(res<0)
            return 0;
        return res;
        //Your code here
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends