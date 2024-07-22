class Solution {
public:
    int getValue(int a, int b, char op) {
        int res;
        switch(op) {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = a / b;
                break;
            default:
                break;
        }
        return res;
    }

    bool isHighPriority(char op) {
        return op == '*' || op == '/';
    }

    int calculate(string s) {
        stack<int> nums;
        stack<char> ops; 
        int num = 0;
        char sign = '+';
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
                if (sign == '+') {
                    nums.push(num);
                } else if (sign == '-') {
                    nums.push(-num);
                } else {
                    int tmp;
                    if (sign == '*') {
                        tmp = nums.top() * num;
                    } else {
                        tmp = nums.top() / num;
                    }
                    nums.pop();
                    nums.push(tmp);
                }
                sign = s[i];
                num = 0;
            }
        }
        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};
