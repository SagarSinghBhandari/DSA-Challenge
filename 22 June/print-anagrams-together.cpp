//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    string generate(string& word){
        vector<int>freq(26,0);
        for(auto x: word){
            freq[x-'a']++;
        }
        string w = "";
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                w+= string(freq[i],i+'a');
            }
        }
        return w;
    }
     vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(auto x:string_list){
            string temp = generate(x);
            mp[temp].push_back(x);
        }
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends