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
    int getDecimalValue(ListNode* head) {
        if(!head) return 0;
        int v=0;
        if(head->val==1) v=1;
        while(head and head->next){
            head=head->next;
            v=v<<1;
            if(head->val==1){
                v=v|1;
            }
        }
        return v;
    }
};