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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* res = dummy;
        
        while(dummy){
            if(dummy->next and dummy->next->next and dummy->next->next->val == dummy->next->val){
                int vl = dummy->next->val;
                ListNode* temp = dummy->next->next;
                while(temp and temp->val == vl){
                    temp = temp->next;
                }
                dummy->next = temp;
            } else{
                dummy = dummy->next;
            }
        }
        return res->next;
    }
};