class Solution {
public:
    void Combinations(int open, int close, vector<string>& res, string str){
        if (open == 0 && close == 0){
            res.push_back(str);
            return ;
        }
        if (open > 0)
            Combinations(open - 1, close, res, str + "(");
        if (close > 0 && close > open)
            Combinations(open, close - 1, res, str + ")");
    }
    vector<string> generateParenthesis(int n){
    vector<string>res;
    Combinations(n, n, res, "");
    return res;
    }
};