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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        
        ListNode* prevNode = dummyNode;
        ListNode* currNode = head;
        while(currNode and currNode->next){
            prevNode->next = prevNode->next->next;
            ListNode* temp = prevNode->next->next;
            prevNode->next->next = currNode;
            currNode->next = temp;
            prevNode = currNode;
            currNode = currNode->next;
        }
        return dummyNode->next;
    }
};