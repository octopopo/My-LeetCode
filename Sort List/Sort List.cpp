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
    ListNode* sortList(ListNode* head) 
    {
        return sortTheList(head);
    }
    
    ListNode* sortTheList(ListNode* head)
    {
        if(!head || !head->next)
        {
            return head;
        }
        
        ListNode *oneStep = head;
        ListNode *twoStep = head;
        
        while(true)
        {
            if(!twoStep->next || !twoStep->next->next)
            {
                break;
            }
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }
        
        ListNode *rightList = sortTheList(oneStep->next);
        oneStep->next = NULL;
        ListNode *leftList = sortTheList(head);
        
        ListNode *newHead, *tempHead;
        if(rightList->val <= leftList->val)
        {
            newHead = rightList;
            rightList = rightList->next;
        }
        else
        {
            newHead = leftList;
            leftList = leftList->next;
        }
        
        tempHead = newHead;
        
        while(leftList || rightList)
        {
            if(leftList && rightList)
            {
                if(rightList->val <= leftList->val)
                {
                    tempHead->next = rightList;
                    rightList = rightList->next;
                }
                else
                {
                    tempHead->next= leftList;
                    leftList = leftList->next;
                }
            }
            else if(leftList)
            {
                tempHead->next = leftList;
                leftList = leftList->next;
            }
            else if(rightList)
            {
                tempHead->next= rightList;
                rightList = rightList-> next;
            }
            
            tempHead = tempHead->next;
        }
        
        return newHead;
    }
};