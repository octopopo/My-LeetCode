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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        int sum = 0;
        ListNode *head = l1;
        ListNode *l1Past = l1;
        ListNode *l2Past = l2;
        
        sum = l1->val + l2->val;
        l1->val = sum%10;
        carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 || l2 || carry == 1){
            if(l1 && l2){
                sum = l1->val + l2->val + carry;
                l1->val = sum%10;
                carry = sum/10;
                l1Past = l1;
                l2Past = l2;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(!l1 && !l2){
                ListNode *tmp = new ListNode(carry);
                l1Past->next = tmp;
                carry = 0;
            }
            else if(l1 && !l2){
                l1->val += carry;
                carry = l1->val/10;
                l1->val = l1->val % 10;
                l1Past = l1;
                l1 = l1->next;
            }
            else{
                l1Past->next = l2;
                l2->val += carry;
                carry = l2->val / 10;
                l2->val %= 10;
                l1Past = l2;
                l2 = l2->next;
            }
        }
            
        return head;
    }
};