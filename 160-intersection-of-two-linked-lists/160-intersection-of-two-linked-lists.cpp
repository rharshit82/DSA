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
        if(!headA or !headB) return NULL;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int l1=0,l2=0;
        while(tempA or tempB){
            if(tempA){
                tempA=tempA->next;
                l1++;
            }
            if(tempB){
               tempB=tempB->next;
                l2++; 
            }
            
        }
        
        int diff=l1-l2;
        if(diff>0)
            while(diff-- !=0) headA=headA->next;
        else
            while(diff++ !=0) headB=headB->next;
        while(headA){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};