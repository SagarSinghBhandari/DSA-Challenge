class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int tn= t.size();
        int left = 0, right;
        unordered_map<char, int> mp, tmp;
        for (char c : t)
            tmp[c]++;
        int count = 0;
        int minLength = INT_MAX; 
        int minLeft = 0;
        
        for (right = 0; right < n; right++) {
            char c = s[right];
            if (tmp.count(c) == 0) continue;
            mp[c]++;
            if (mp[c] <= tmp[c]) count++;
            if (count == tn) {
                while (tmp.count(s[left])==0|| mp[s[left]]>tmp[s[left]]) {
                    if (mp.count(s[left])!=0) mp[s[left]]--;
                    left++;
                }
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }
            }
        }
        if (minLength == INT_MAX) return "";
    
        return s.substr(minLeft, minLength);
    }
};