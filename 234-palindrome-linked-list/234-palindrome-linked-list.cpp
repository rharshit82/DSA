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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* p=NULL;
        ListNode* q=head;
        ListNode* r=NULL;
        while(slow and fast and fast->next){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        if(fast) slow=slow->next;
        while(p and slow){
            if(slow->val!=p->val) return false;
            slow=slow->next;
            p=p->next;
        }
        return true;
    }
};