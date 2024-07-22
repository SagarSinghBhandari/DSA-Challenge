class Solution {
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(auto x:strs){
            string temp = generate(x);
            mp[temp].push_back(x);
        }
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};