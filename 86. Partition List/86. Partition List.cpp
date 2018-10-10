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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
        {
            return NULL;
        }
        ListNode *smallHead = new ListNode(0);
        ListNode *bigHead = new ListNode(0);
        ListNode *oldBig = bigHead;
        ListNode *oldSmall = smallHead;
        while(head)
        {
            //cout << head->val << endl;
            if(head->val < x)
            {
                smallHead->next = head;
                smallHead = smallHead->next;
            }
            else
            {
                bigHead->next = head;
                bigHead = bigHead->next;
            }
            head = head->next;
        }
        smallHead->next = NULL;
        bigHead->next = NULL;
        smallHead->next = oldBig->next;
        return oldSmall->next;
    }
};