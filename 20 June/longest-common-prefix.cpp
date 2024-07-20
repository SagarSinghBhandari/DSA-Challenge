bool cmp(string s1, string s2){
    return s1<s2;
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(),strs.end(),cmp);
       string s = strs[0],res="";
       bool check = false;
       for(int i = 0; i<s.size(); i++){
        int cnt = 0;
         for(auto x: strs){
            if(s[i]==x[i])
                cnt++;
            else{
                check = true;
                break;
            }
         }
         if(check)
            break;
         else if(cnt == strs.size())
            res += s[i];  
       }
       return res; 
    }
};