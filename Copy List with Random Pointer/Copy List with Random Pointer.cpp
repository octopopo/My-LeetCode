/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode*, RandomListNode*> m_map;
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *tempNodePointer;
        if(!head){
            return NULL;
        }
        auto it = m_map.find(head);
        auto endN = m_map.end();
        if(it != endN)
        {
            return m_map[head];
        }
        if(it == endN)
        {
            tempNodePointer = new RandomListNode(head->label);
            m_map[head] = tempNodePointer;
            tempNodePointer->next = copyRandomList(head->next);
            tempNodePointer->random = copyRandomList(head->random);
        }
        return m_map[head];
    }
};