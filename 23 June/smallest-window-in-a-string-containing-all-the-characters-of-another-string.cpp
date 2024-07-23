//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if(p.size()>s.size())
            return "-1";
        
        vector<int>pmap(26,0), smap(26,0);
        
        for(int i=0; i<p.size(); i++){
            pmap[p[i]-'a']++;
        }
        
        int cnt = 0;
        int idx = -1, len = INT_MAX,begin = 0;
        
        for(int i=0; i<s.size(); i++){
            smap[s[i]-'a']++;
            
            if(pmap[s[i]-'a']!= 0 && smap[s[i]-'a'] <= pmap[s[i]-'a']){
                cnt++;
            }
            
            while(cnt == p.size()){
                if(i - begin + 1 < len){
                    len = i - begin + 1;
                    idx = begin;
                }
                
                smap[s[begin]-'a']--;
                if(pmap[s[begin]-'a']!= 0 && smap[s[begin]-'a'] < pmap[s[begin]-'a']){
                    cnt--;
                }
                begin++;
            }
        }
        
        if(idx == -1)
            return "-1";
        
        return s.substr(idx,len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends