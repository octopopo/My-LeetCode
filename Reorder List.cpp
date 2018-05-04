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
        ListNode *list;
        ListNode *pt = head;
        vector<ListNode*> m_vec;
        
        if(!head){
            return;
        }
        
        while(pt != NULL){
            m_vec.push_back(pt);
            pt = pt->next;
        }
        
        pt = head;
        int vSize = m_vec.size();
        ListNode *tp = new ListNode(0);
        
        cout << m_vec.size() << endl;
        for(int i = 0; i < vSize/2; i++){
            tp = pt->next;
            pt->next = m_vec[vSize-1-i];
            m_vec[vSize-1-i]->next = tp;
            pt = tp;
        }
        
        pt->next = NULL;
        
    }
};