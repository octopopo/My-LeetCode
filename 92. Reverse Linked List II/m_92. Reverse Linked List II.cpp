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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *reverseHead, *reverseTail;
        ListNode *beforeHead, *afterTail;
        bool isEnd = false;
        if(m == n)
        {
            return head;
        }
        
        ListNode *walker = new ListNode(0);
        walker->next = head;
        
        int count = 0;
        
        //get all the pointer to the node I need
        while(walker)
        {
            if(count+1 == m)
            {
                beforeHead = walker;
            }
            else if(count == m)
            {
                reverseHead = walker;
            }
            else if(count == n)
            {
                reverseTail = walker;
            }
            else if(count == n+1)
            {
                afterTail = walker;
                isEnd = true;
                break;
            }
            walker = walker->next;
            count++;
        }
        
        if(!isEnd)
        {
            afterTail = new ListNode(0);
            reverseTail->next = afterTail;
        }
        
        //try to reverse the list between
        walker = reverseHead;
        ListNode *secondWalker = walker->next;
        ListNode *oldNode;
        while(secondWalker != afterTail && secondWalker)
        {
            oldNode = walker;
            walker = secondWalker;
            secondWalker = secondWalker->next;
            walker->next = oldNode;
        }
        beforeHead->next = reverseTail;
        if(!isEnd)
        {
            reverseHead->next = NULL;
        }
        else
        {
            reverseHead->next = afterTail;
        }
        
        return m == 1 ? beforeHead->next : head;
    }
};