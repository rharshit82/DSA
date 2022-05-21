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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        bool first=true;
        int carry=0;
        ListNode* head;
        ListNode* res;
        while(l1 or l2 or carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            if(first){
                res = new ListNode(sum);
                head=res;
                first=false;
            }
            else{
                ListNode* temp = new ListNode(sum);
                head->next=temp;
                head=head->next;
            }
        }
        return res;
       
    }
};