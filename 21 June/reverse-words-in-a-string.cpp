class Solution {
public:
    string reverseWords(string s) {
        string str;
        vector<string>res;
        s += ' ';
        for(int i = 0; i<s.size(); i++){
            if(isalnum(s[i])){
                str += s[i];
            }
            else if(s[i]==' '){
                res.push_back(str);
                str = "";
            }
        }
        str = "";
        reverse(res.begin(),res.end());
        for(auto x:res){
            str += x;
            if(!x.empty()){
                str += ' ';
            }
        }
        if(str[str.size()-1]==' ')
         str.erase(str.size()-1,1);
        return str;
    }
};