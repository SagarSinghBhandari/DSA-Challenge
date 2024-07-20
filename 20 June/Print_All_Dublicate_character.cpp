class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else if(st.empty() && (s[i]==')' || s[i] == '}' || s[i]==']') )
            return false ;
        else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')){
            if(!st.empty())
            st.pop();
        }
        else 
            break;
       }
        if(st.empty())
            return true;
        return false;
    }
};