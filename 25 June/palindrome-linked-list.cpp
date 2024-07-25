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
    bool isPalindrome(ListNode* head) {
       ListNode* temp = head;
       ListNode* h2 = NULL;
        while(temp){
            ListNode* current = new ListNode;
            current->val = temp->val;
            if(h2==0){
                h2 = current;
            }
            else{
                current->next = h2;
                h2 = current;
            }
            temp = temp->next;
        }
        while(head!=NULL && h2!=NULL){
            if(head->val != h2->val)
                return false;
            head = head->next;
            h2 = h2->next;
        }
        return true;
        }
};