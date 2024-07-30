//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int compute(int a, int b, char op){
        switch(op){
            case '*':
                return a*b;
                break;
            case '/':
                return a/b;
                break;
            case '+':
                return a+b;
                break;
            case '-':
                return a-b;
                break;
        }
        return -1;
    }
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        for(int i=0; i<S.size(); i++){
            if(S[i]>='0' && S[i]<='9')
                st.push(S[i]-'0');
            else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = compute(a,b,S[i]);
                st.push(res);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends