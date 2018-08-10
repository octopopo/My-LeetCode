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
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if(!head)
        {
            return NULL;
        }
        
        RandomListNode *tempHead = head;
        RandomListNode *newNode;
        RandomListNode *next;
        //copy the whole list with only next pointer
        while(tempHead)
        {
            next = tempHead->next;
            
            newNode = new RandomListNode(tempHead->label);
            newNode->next = next;
            tempHead->next = newNode;
            //becasue next head are now the new node
            //go to the next next will go to the next node of the original list
            tempHead = next;
        }
        
        //now we have to copy the random pointer for every new node;
        tempHead = head;
        
        while(tempHead)
        {
            //the new node random have to point to the new random node
            if(tempHead->random)
            {
                tempHead->next->random = tempHead->random->next;
            }
            tempHead = tempHead->next->next;
        }
        
        //last Step, clear the original list
        RandomListNode *pseudoHead = new RandomListNode(0);
        tempHead = head;
        RandomListNode* copy, *copyHead;
        copyHead = pseudoHead;
        while(tempHead)
        {
            next = tempHead->next->next;
            
            copy = tempHead->next;
            copyHead->next = copy;
            copyHead = copy;
            
            tempHead->next = next;
            
            tempHead = next;
        }
        
        return pseudoHead->next;
    }
};