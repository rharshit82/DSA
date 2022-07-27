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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return headB;
        if(!headB) return headA;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA and tempB and tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
            if(tempA == tempB) return tempA;
            if(!tempA) tempA = headB;
            if(!tempB) tempB = headA;
        }
        return tempA;
    }
};