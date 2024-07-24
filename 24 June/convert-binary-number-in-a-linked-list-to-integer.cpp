/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res =0, i=0;
        stack<int>st;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty()){
            if(st.top()==1)
                res += pow(2,i);
            i++;
            st.pop();
        }
        return res;
    }
};