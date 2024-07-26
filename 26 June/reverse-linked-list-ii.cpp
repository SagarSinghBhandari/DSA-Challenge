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
    ListNode* getNode(ListNode* head, int n){
        while(n--){
            head = head->next;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l = getNode(head,left-1);
        ListNode* r = getNode(head,right-1);
        if(l==NULL || r==NULL)
            return head;
        while(left<right){
            ListNode* temp = getNode(head,right-1);
            if(temp==NULL && l==NULL)
                return head;
            int k = l->val;
            l->val = temp->val;
            temp->val = k;
            l = l->next;
            right--;
            left++;
        }
        return head;
    }
};