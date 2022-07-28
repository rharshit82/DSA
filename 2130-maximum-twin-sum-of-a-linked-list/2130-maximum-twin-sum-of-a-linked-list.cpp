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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* curr = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* p = head;
        ListNode* q = head;
        ListNode* r = head;
        while(q!=slow){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        ListNode* start = p;
        ListNode* mid = slow;
        int res=0;
        while(start and mid){
            res = max(res, start->val + mid->val);
            start = start->next;
            mid = mid->next;
        }
        return res;
    }
};