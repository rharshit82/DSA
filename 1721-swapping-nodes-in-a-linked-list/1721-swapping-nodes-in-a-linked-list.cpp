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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        while(--k){
            curr = curr->next;
        }
        ListNode* kth = curr;
        curr = curr->next;
        ListNode* slow = head;
        while(curr){
            curr = curr->next;
            slow = slow->next;
        }
        swap(slow->val, kth->val);
        return head;
    }
};