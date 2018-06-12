class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *temp;
        ListNode *first = NULL;
        while(l1 || l2){
            if(l1 && l2){
                if(l1->val <= l2->val){
                    temp = l1;
                    l1 = l1 -> next;
                }
                else{
                    temp = l2;
                    l2 = l2->next;
                }
            }
            else if(l1){
                temp = l1;
                l1 = l1->next;
            }
            else if(l2){
                temp = l2;
                l2 = l2 -> next;
            }
            
            if(res == NULL){
                res = temp;
                first = temp;
            }
            else{
                res->next = temp;
                res = res->next;
            }
        }
        
        return first;
    }
};