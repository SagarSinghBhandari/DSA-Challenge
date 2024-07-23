class Solution {
public:
    string helper(int num, const vector<string>& belowTwenty, const vector<string>& tens) {
        if (num == 0) return "";
        else if (num < 20) return belowTwenty[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10, belowTwenty, tens);
        else return belowTwenty[num / 100] + " Hundred " + helper(num % 100, belowTwenty, tens);
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
        "Seventeen", "Eighteen", "Nineteen"};
        vector<string>ones = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string>thousands = {"", "Thousand", "Million", "Billion"};
        string res = "";
        
        for (int i = 0; i < thousands.size() && num > 0; ++i) {
            if (num % 1000 != 0) {
                if(res.empty()){
                   res = helper(num % 1000, belowTwenty, ones) + thousands[i];
                }
                else{
                    res = helper(num % 1000, belowTwenty, ones) + thousands[i] + " " + res;
                }
            }
            num /= 1000;
        } 
        if(res[res.size()-1]==' ')
            res.pop_back();   
        return res;
    }
};