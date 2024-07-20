class Solution {
public:
    int strStr(string haystack, string needle) {
       int res = -1,j,k,i;
       for(i=0; i<haystack.size(); i++){
        k = i;
        for(j = 0; j<needle.size(); j++){
            if(needle[j]!=haystack[k])
                break;
            k++;
        }
        if(j == needle.size()){
            res = i;
            break;
        }
       }
       return res; 
    }
};