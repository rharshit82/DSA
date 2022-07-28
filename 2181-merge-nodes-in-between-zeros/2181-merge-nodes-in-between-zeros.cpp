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
    ListNode* mergeNodes(ListNode* head) {
        if(!head or !head->next) return head;
        int sum=0;
        ListNode* dummy = head;
        ListNode* temp = dummy;
        head = head->next;
        while(head){
            if(head->val == 0){
                head->val = sum;
                temp->next = head;
                temp = temp->next;
                sum=0;
            } else{
                sum+=head->val;
            }
            head = head->next;
        }
        return dummy->next;
    }
};