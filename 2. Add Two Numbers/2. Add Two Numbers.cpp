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
        ListNode *nHead = l1;
        int isCarry = 0;
        int temp;
        while(l1 && l2)
        {
            temp = l1->val + l2->val + isCarry;
            l1->val = temp%10;
            isCarry = temp/10;
            if(!l1->next || !l2->next)
            {
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(!l1->next && !l2->next)
        {
            if(isCarry == 1)
            {
                ListNode *newN = new ListNode(1);
                l1->next = newN;
            }
        }
        else if(!l2->next)
        {
            l1 = l1->next;
            while(isCarry == 1)
            {
                temp = l1->val + isCarry;
                l1->val = temp%10;
                isCarry = temp/10;
                if(!l1->next && isCarry == 1)
                {
                    ListNode *newN = new ListNode(1);
                    l1->next = newN;
                    isCarry = 0;
                }
                l1 = l1->next;
            }
        }
        else if(!l1->next)
        {
            l1->next = l2->next;
            l1 = l1->next;
            while(isCarry == 1)
            {
                temp = l1->val + isCarry;
                l1->val = temp%10;
                isCarry = temp/10;
                if(!l1->next && isCarry == 1)
                {
                    ListNode *newN = new ListNode(1);
                    l1->next = newN;
                    isCarry = 0;
                }
                l1 = l1->next;
            }
        }
        
        return nHead;
    }
};