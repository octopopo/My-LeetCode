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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //the purpose of finder is to get the desire distance between another pointer
        ListNode *finder = head;
        
        for(int i = 0; i < n; i++)
        {
            finder = finder->next;
        }
        
        //that is to say, the node we want to delete is the first one.
        if(!finder)
        {
            return head->next;
        }
        //Now the distance between this pointer and finder is n
        ListNode *removePtr = head;
        
        //when finder go all the way til the end.
        //remove pointer will just stand on the node which is one before the target node
        while(finder->next)
        {
            finder = finder->next;
            removePtr = removePtr->next;
        }
        
        removePtr->next = removePtr->next->next;
        
        return head;
    }
};