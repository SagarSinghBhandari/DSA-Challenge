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
    ListNode* partition(ListNode* head, int x) {
      if(head==NULL)
       return head;  
      ListNode* small = new ListNode(0);
      ListNode* large = new ListNode(0);
       ListNode* sptr = small;
       ListNode* lptr = large;
      while(head){
        if(head->val < x){
          sptr->next = head;
          sptr = sptr->next;  
        }
        else{
          lptr->next = head;
          lptr = lptr->next;   
        }
        head = head->next;  
      }
      sptr->next = large->next;
      lptr->next = NULL;
      return small->next;
    }
};