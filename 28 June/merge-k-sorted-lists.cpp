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
    ListNode* merge(ListNode* list1,ListNode* list2){
       if(!list1)
        return list2;
       if(!list2)
        return list1;

       if((list2->val) <= (list1->val)){
           list2->next = merge(list1,list2->next);
           return list2;
       }
       else{
           list1->next = merge(list1->next,list2);
           return list1;
       }
     return NULL;  
    }
    ListNode* partition(vector<ListNode*>& lists, int start , int end){
      if(start>end)
       return NULL;
      if(start==end)
       return lists[start];
      int mid = start + (end-end)/2; 
      ListNode* h1 = partition(lists,start,mid);
      ListNode* h2 = partition(lists,mid+1,end);
      return merge(h1,h2);    
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int n = lists.size();
      if(n==0)
       return NULL;
      return partition(lists,0,n-1); 
    }
};