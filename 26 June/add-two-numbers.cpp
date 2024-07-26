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
    ListNode* join(ListNode* head, int v){
        ListNode* current = new ListNode();
        current->val = v;
        current->next = NULL;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long a = 0, b=0,carry=0,sum =0;
        ListNode* h = new ListNode();
        h = NULL;
        while(l1 && l2){
            a = l1->val;
            b = l2->val;
            sum = a+b+carry;
            carry = sum/10;
            h = join(h,sum%10); 
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            l1->val += carry; 
            carry = (l1->val)/10;
            h = join(h,(l1->val)%10);
            l1 = l1->next;
        }
        while(l2){
            l2->val += carry; 
            carry = (l2->val)/10;
            h = join(h,(l2->val)%10);
            l2 = l2->next;
        }
        if(carry){
            h = join(h,carry);
        }
        return h;             
    }
};