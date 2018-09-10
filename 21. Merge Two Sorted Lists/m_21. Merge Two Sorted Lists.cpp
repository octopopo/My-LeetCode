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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *fakeHead = new ListNode(0);
        ListNode *head = fakeHead;
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                fakeHead->next = l1;
                l1 = l1->next;
            }
            else
            {
                fakeHead->next = l2;
                l2 = l2->next;
            }
            fakeHead = fakeHead->next;
        }
        
        if(l1)
        {
            fakeHead->next = l1;
        }
        if(l2)
        {
            fakeHead->next = l2;
        }
        
        return head->next;
    }
};