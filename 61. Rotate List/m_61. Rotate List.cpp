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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
        {
            return head;
        }
        int listCount = 0;
        ListNode *walker = head;
        while(walker != NULL)
        {
            walker = walker->next;
            listCount++;
        }
        //for rotation that is 
        k = k % listCount;
        if(k == 0)
        {
            return head;
        }
        
        ListNode *newHead = head;
        walker = newHead;
        for(int i = 0; i < listCount-k-1; i++)
        {
            walker = walker->next;
        }
        newHead = walker->next;
        walker->next = NULL;
        ListNode *secWalker = newHead;
        while(secWalker->next != NULL)
        {
            secWalker = secWalker->next;
        }
        secWalker->next = head;
        
        return newHead;
    }
};