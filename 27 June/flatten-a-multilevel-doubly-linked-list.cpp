/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while(curr) {
            if(curr->child){
                Node* childTail = curr->child;
                while(childTail->next){
                    childTail = childTail->next;
                }
                childTail->next = curr->next;
                if(curr->next){
                    curr->next->prev = childTail;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
};
