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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        int sz = 0;
        while(temp){
            st.push(temp);
            sz++;
            temp = temp->next;
        }
        for(int i=0; i<sz/2; i++){
            ListNode* curr = st.top();
            st.pop();
            curr->next = head->next;
            head->next = curr;
            head = head->next->next;
        }
        head->next = NULL;
    }
};