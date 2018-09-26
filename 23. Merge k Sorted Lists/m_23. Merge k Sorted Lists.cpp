/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool comparefunction(ListNode* a, ListNode *b)
{
    if(!a)
    {
        return false;
    }
    if(!b)
    {
        return true;
    }
    return a->val < b->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int lL = lists.size();
        if(lL == 0)
        {
            return NULL;
        }
        sort(lists.begin(), lists.end(), comparefunction);
        int i;
        for(i = lL-1; i >=0; i--)
        {
            if(lists[i])
            {
                break;
            }
            cout << i << endl;
        }
        int remainList = i;
        int headP = 0;
        ListNode *fakeHead = new ListNode(0);
        if(!lists[0])
        {
            return NULL;
        }
        ListNode *head = fakeHead;
        while(lists[headP])
        {
            head->next = lists[headP];
            head = head->next;
            lists[headP] = lists[headP]->next;
            //cout <<"targetNow: " << head->val << endl;
            if(!lists[headP])
            {
                headP++;
                if(headP > remainList)
                {
                    return fakeHead->next;
                }
                continue;
            }
            //cout << remainList <<endl;
            sort(lists.begin()+headP, lists.begin()+remainList+1, comparefunction);
        }
        
        return fakeHead->next;
    }
};