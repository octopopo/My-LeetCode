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
    bool hasCycle(ListNode *head) {
        
        if(!head || !head->next || !head->next->next)
        {
            return false;
        }
        
        ListNode *oneStep = head;
        ListNode *twoStep = head;
        
        while(true)
        {
            if(!twoStep->next || !twoStep->next->next)
            {
                break;
            }
            twoStep = twoStep->next->next;
            oneStep = oneStep->next;
            if(oneStep->val == twoStep->val)
            {
                return true;
            }
        }
        
        return false;
    }
};