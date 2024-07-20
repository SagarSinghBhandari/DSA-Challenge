/*
* APPROACH:
*   First, sort the input array.
*   Then using two pointers calculate the difference between the maximum element 
*   and the minimum element in the current subarray. 
*/ 

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    int j = 0, i=0;
    long long int ans = 1e9;
    while(i+m-1<n){
        j = i+m-1;
        long long int d = a[j]-a[i];
        ans = min(ans,d);
        i++;
    }
    return ans;
    }   
};
