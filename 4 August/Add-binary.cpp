class Solution {
public:
    string addBinary(string a, string b){
        int c=0;
        int i=a.size()-1,j=b.size()-1;
        int nm1,nm2;
        string s="";
        while(i>=0 || j>=0){
           nm1=0,nm2=0;
           if(i>=0)nm1+=a[i]-'0';
           if(j>=0)nm2+=b[j]-'0';
           nm1+=nm2+c;
           if(nm1==0)s='0'+s;
           else if(nm1==1){
               s='1' + s;
               c=0;
           }
           else if(nm1==2){
               s='0'+s;
               c=1;
           }
           else {
               s='1'+s;
               c=1;
           }
           i--;
           j--;
        }
        if(c)s='1'+s;
        return s;
    }
};