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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode *tempHead, *reverseHead, *disHead;
        disHead = head->next;
        reverseHead = head;
        reverseHead->next = NULL;
        while(disHead->next)
        {
            tempHead = disHead;
            disHead = disHead->next;
            tempHead->next = reverseHead;
            reverseHead = tempHead;
        }
        
        disHead->next = reverseHead;
        return disHead;
    }
};