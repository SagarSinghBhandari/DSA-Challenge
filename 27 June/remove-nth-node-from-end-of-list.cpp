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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int l=0;
      ListNode* temp = head;
      ListNode* prev = NULL;
      while(temp){
          l++;
          temp = temp->next;
      }
      l = l-n;
      temp = head;
      if(l==0){
          head = temp->next;
      }
      else{
        while(l){
            prev = temp;
            temp = temp->next;
            l--;
        }
        if(prev!=NULL && temp!=NULL)
            prev->next = temp->next;
      }
      return head;
    }
};