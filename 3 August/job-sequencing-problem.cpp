//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(pair<int,int>& a , pair<int,int>&b){
        return a.first > b.first;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>>jobs;// your code here
        for(int i=0; i<n; i++){
            jobs.push_back({arr[i].profit,arr[i].dead});
        }
        sort(jobs.begin(),jobs.end(),cmp);
        
        int maxTime = 0;
        for(int i=0; i<n; i++){
            maxTime = max(maxTime,jobs[i].second);
        }
        
        vector<int>t(maxTime,-1);
        int job = 0, profit = 0;
        
        for(int i=0; i<n; i++){
            int j = jobs[i].second -1;
            while(j>=0 && t[j]!=-1)
                j--;
            if(j>=0 && t[j]==-1){
                t[j] = i;
                job++;
                profit += jobs[i].first;
            }
        }
        return {job,profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends