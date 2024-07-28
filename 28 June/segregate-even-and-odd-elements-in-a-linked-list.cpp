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
    ListNode* insert(ListNode* head, int v){
        ListNode* current = new ListNode();
        current->val = v;
        if(head==NULL){
            head = current;
        }
        else{
            ListNode* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = current;
        }
        return head;
    }
    ListNode* oddEvenList(ListNode* head) {
        ListNode* h = NULL;
        ListNode* temp = head;
        int n = 1;
        while(temp){
            if(n%2!=0){
                h = insert(h,temp->val);
            }
            n++;
            temp = temp->next;
        }
        temp = head;
        n = 1;
        while(temp){
            if(n%2==0){
                insert(h,temp->val);
            }
            n++;
            temp = temp->next;
        }
        return h;
    }
};