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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyEven = new ListNode();
        ListNode* dummyOdd = new ListNode();
        ListNode* dummyOddStart = dummyOdd;
        ListNode* dummyEvenStart = dummyEven;
        int i=1;
        while(head){
            if(i%2==0){
                dummyEven->next = head;
                dummyEven = dummyEven->next;
            } else{
                dummyOdd->next = head;
                dummyOdd = dummyOdd->next;
            }
            i++;
            head = head->next;
        }
        dummyOdd->next = dummyEvenStart->next;
        dummyEven->next = NULL;
        return dummyOddStart->next;
    }
};