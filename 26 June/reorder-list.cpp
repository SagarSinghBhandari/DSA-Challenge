class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* next = NULL;
        slow->next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p2 != NULL) {
            ListNode* temp1 = p1->next;
            ListNode* temp2 = p2->next;
            p1->next = p2;
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;
        }
    }
};
