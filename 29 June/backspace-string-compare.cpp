class Solution {
public:
    bool backspaceCompare(string s, string t) {
    int i=0,top2=-1,top1=-1;
    char stk1[s.size()],stk2[t.size()];
    for(i=0; i<s.size(); i++){
      if(s[i]>='a' && s[i]<='z'){
        stk1[++top1] = s[i];
      }
      else if(s[i]=='#'){
          if(top1>=0)
          top1--;
      } 
    }
     for(i=0; i<t.size(); i++){
      if(t[i]>='a' && t[i]<='z'){
        stk2[++top2] = t[i];
      }
      else if(t[i]=='#'){
          if(top2>=0)
          top2--;
      }
    }
    if(top1!=top2){
    return false;
    }
     for(i=0; i<=top1; i++){
       if(stk1[i]!= stk2[i]){
         return false;
       }
     }
     return true;
    }
};