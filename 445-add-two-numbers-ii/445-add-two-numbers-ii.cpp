class Solution {
public:
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        stack<int> s1, s2;
        while (h1) {
            s1.push(h1->val);
            h1 = h1->next;
        }
        while (h2) {
            s2.push(h2->val);
            h2 = h2->next;
        }
        int carry_on = 0;
        ListNode *curr = NULL, *prev = NULL;
        while (s1.size() || s2.size() || carry_on) {
            int sum = carry_on;
            if (s1.size()) {
                sum += s1.top();
                s1.pop();
            }
            if (s2.size()) {
                sum += s2.top();
                s2.pop();
            }
            carry_on = sum / 10;
            prev = new ListNode(sum % 10);
            prev->next = curr;
            curr = prev;
        }
        return curr;
    }
};