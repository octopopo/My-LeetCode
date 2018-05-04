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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode *mid = cutList(head);
        ListNode *re = reverseList(mid);
        combineList(head, re);
        
    }
    
    ListNode* cutList(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    
    ListNode *reverseList(ListNode *head){
        if(!head)
            return NULL;
        ListNode *pt = head;
        ListNode *npt = head->next;
        ListNode *tpt = new ListNode(0);
        while(npt){
            tpt = npt;
            npt = npt->next;
            tpt->next = pt;
            pt = tpt;
        }
        head->next = NULL;
        return pt;
    }
    
    void combineList(ListNode* headList, ListNode* midList){
        ListNode *fpt = headList;
        ListNode *spt = midList;
        
        ListNode *now = fpt;
        fpt = fpt->next;
        
        while(fpt || spt){
            if(spt){
                now->next = spt;
                spt = spt->next;
                now = now->next;
            }
            if(fpt){
                now->next = fpt;
                fpt = fpt->next;
                now = now->next;
            }  
        }
    }
};