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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode *swapNode;
        ListNode *tempHead;
        ListNode *firNode, *secNode;
        ListNode *trueHead = new ListNode(0);
        trueHead->next = head;
        tempHead = trueHead;
        firNode = tempHead->next;
        secNode = tempHead->next->next;
        while(firNode && secNode)
        {
            swapNode = secNode->next;
            tempHead->next = secNode;
            secNode->next = firNode;
            firNode->next = swapNode;
            
            tempHead = tempHead->next->next;
            firNode = tempHead->next;
            if(!firNode)
            {
                break;
            }
            secNode = firNode->next;
            if(!secNode)
            {
                break;
            }
        }
        
        return trueHead->next;
    }
};