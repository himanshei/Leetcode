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
    ListNode *detectCycle(ListNode *head) {
       if(head==NULL)return NULL;
       ListNode*d=new ListNode(-1);
       d->next=head;
       ListNode*slow=d;
       ListNode*fast=d;
       while(fast!=NULL&& fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
       }
       if(slow!=fast) return NULL;
       while(slow!=d){
        slow=slow->next;
        d=d->next;
       }
       return slow;
    }
};