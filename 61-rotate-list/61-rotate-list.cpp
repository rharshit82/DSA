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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k==0) return head;
        
        int sz=1;
        ListNode* curr = head;
        while(curr->next){
            sz++;
            curr= curr->next;
        }
        k=k%sz;
        k = sz-k;
        ListNode* res;
        curr ->next = head;
        for(int i=0; i<k; i++){
            curr = curr->next;
        }
        res = curr->next;
        curr->next = NULL;
        return res;
    }
};