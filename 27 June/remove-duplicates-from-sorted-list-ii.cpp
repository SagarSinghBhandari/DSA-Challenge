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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* begin = new ListNode(0);
        if(head==NULL || head->next==NULL)
            return head;
        begin->next = head;
        ListNode* temp = head;
        ListNode* prev = begin;
        while(temp){
            bool flag = false;
            while( temp->next!=NULL && temp->val == temp->next->val){
                    temp = temp->next;
                    flag = true;
            }
            if(flag)
                prev->next = temp->next;
            else
                prev = prev->next;
            temp = temp->next;
        }   
        return begin->next;
    }
};