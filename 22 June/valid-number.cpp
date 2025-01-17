class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), i = 0, digits = 0, dots = 0;
        for (i=0; i < n && isspace(s[i]); i++);
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++) {
            isdigit(s[i]) ? digits++ : dots++;
        }
        if (!digits || dots > 1) {
            return false;
        }
        if (s[i] == 'e' || s[i] == 'E') {
            i++;
            if (s[i] == '+' || s[i] == '-') {
                i++;
            }
            digits = 0;
            for (; i < n && isdigit(s[i]); i++) {
                digits++;
            }
            if (!digits) {
                return false;
            }
        }
        for (; i < n && isspace(s[i]); i++);
        return i == n;
    }
};