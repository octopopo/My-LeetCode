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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode *newH = new ListNode(INT_MAX);
        newH->next = head;
        ListNode *current = newH;
        while(current){
            if(current->next){
                if(current->next->val == val){
                    if(current->next->next){
                        current->next = current->next->next;
                    }
                    else
                        current->next = NULL;
                }
                if(current->next && current->next->val != val)
                    current = current->next;
            }
            else
                break;
        }
        return newH->next;
    }
};