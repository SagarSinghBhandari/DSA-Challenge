/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* res = NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int a=0,b=0;

        while(temp1){
            a++;
            temp1 = temp1->next;
        }
        while(temp2){
            b++;
            temp2 = temp2->next;
        }
        if(a>b){
            a = a-b;
            temp1 = headA;
            temp2 = headB;
        }
        else{
            a = b-a;
            temp1 = headB;
            temp2 = headA;
        }
        while(a--){
            temp1 = temp1->next;
        }
        while(temp1 && temp2){
            if(temp1 == temp2){
                res = temp1;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return res;
    }
};