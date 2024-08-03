class Solution {
public:
    int answer(vector<int>& ans,int i,vector<int>& memo){
        if(i==(ans.size()-1)){
            return ans[i];
        }
        if(i>=(ans.size())){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        int first=0;
        first=ans[i]+answer(ans,i+2,memo);
        
        int second=0;
        second=ans[i+1]+answer(ans,i+3,memo);
        
        memo[i]=max(first,second);
        return max(first,second);
    }
    int deleteAndEarn(vector<int>& arr) {
        int n=*max_element(arr.begin(), arr.end())+1;
        vector<int> ans(n,0);
        vector<int> memo(n,-1);
        
        for(int i=0;i<arr.size();i++){
            ans[arr[i]]+=arr[i];
        }
        int earn=0;
        earn=answer(ans,0,memo);
        return earn;
    }
};