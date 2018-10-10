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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return NULL;
        }
        
        ListNode *newHead;
        int target = head->val;
        newHead = head;
        head = head->next;
        bool needNewHead = false;
        //set the head
        while(head)
        {
            if(head->val == target)
            {
                needNewHead = true;
            }
            else
            {
                if(!needNewHead)
                {
                    break;
                }
                else
                {
                    newHead = head;
                    target = newHead->val;
                    needNewHead = false;
                }
            }
            head = head->next;
        }
        
        if(needNewHead)
        {
            return NULL;
        }
        
        //now I got the newHead should go through the whole list
        if(!newHead->next)
        {
            return newHead;
        }
        ListNode *walker = newHead->next;
        ListNode *listTail = newHead;
        ListNode *slowWalker;
        needNewHead = false;
        if(!walker->next)
        {
            return newHead;
        }
        target = walker->val;
        slowWalker = walker;
        walker = walker->next;
        while(walker)
        {
            //cout << walker->val << " " << target << endl;
            if(walker->val == target)
            {
                needNewHead = true;
            }
            else
            {
                if(!needNewHead)
                {
                    //cout << "slowWalker: " << slowWalker->val << endl;
                    listTail->next = slowWalker;
                    listTail = listTail->next;
                }
                target = walker->val;
                needNewHead = false;
            }
            slowWalker = walker;
            walker = walker->next;
        }
        
        if(!needNewHead)
        {
            listTail->next = slowWalker;
        }
        else
        {
            listTail->next = NULL;
        }
        
        return newHead;
    }
};