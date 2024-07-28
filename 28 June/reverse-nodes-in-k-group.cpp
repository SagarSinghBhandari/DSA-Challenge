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
    void Reverse(ListNode* head,ListNode* end){
    ListNode* current = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while(prev!= end){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
 }	
}
    ListNode* reverseK(ListNode* head, int k){
    if(head==NULL||head->next==NULL||k==1)
    {
        return head;
    }
    int count=1;
    ListNode* start = head;
    ListNode* end = head;
    while(count<k)
    {
        count++;
        end = end->next;
        if(end == NULL)
         return head;
    }
    ListNode* nexthead = reverseK(end->next,k);
    Reverse(start,end);
    start->next=nexthead;
    return end;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
      head = reverseK(head,k);
      return head;
    }
};