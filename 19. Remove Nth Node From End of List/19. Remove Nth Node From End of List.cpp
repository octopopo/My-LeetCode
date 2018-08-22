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
    int count = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = goDeep(head, n);
        return head;
    }
    
    ListNode *goDeep(ListNode *head, int target)
    {
        //reach the end
        if(!head)
        {
            count = 0;
            return NULL;
        }
        head->next = goDeep(head->next, target);
        count++;
        
        return count == target ? head->next : head;
    }
};