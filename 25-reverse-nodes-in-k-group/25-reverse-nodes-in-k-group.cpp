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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next or k==1) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy;
        ListNode* nex = dummy;
        int sz=0;
        ListNode* temp = dummy;
        while(head){
            sz++;
            head = head->next;
        }
        while(sz>=k){
             cur = pre->next;
             nex = cur->next;
            for(int i=1; i<k; i++){
                cur->next = nex->next;
                nex->next=pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre=cur;
            sz-=k;
        }
        return dummy->next;
    }
};