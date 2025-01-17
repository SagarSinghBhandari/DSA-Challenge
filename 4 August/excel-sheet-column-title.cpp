class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            result.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;    
        }
        reverse(result.begin(), result.end());
        return result;
    }
};