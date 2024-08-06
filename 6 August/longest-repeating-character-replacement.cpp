class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;
        int left = 0;
        int start = 0;
        int result = 0;

        while (start < s.size()) {
            count[s[start] - 'A']++;

            maxCount = max(maxCount, count[s[start] - 'A']);
            if (start - left + 1 - maxCount > k) {
                count[s[left] - 'A']--; 
                left++;
            }
            result = max(result, start - left + 1);
            start++; 
        } 
        return result;
    }
};