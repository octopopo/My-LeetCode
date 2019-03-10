/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return NULL;
        }
        unordered_map<Node*, Node*> ListMap;
        
        Node *oldWalker = head;
        Node *newWalker;
        
        Node* newHead = new Node(head->val, head->next, head->random);
        newWalker = newHead;
        oldWalker = head->next;
        ListMap[head] = newHead;
        while(oldWalker)
        {
            Node *newNode = new Node(oldWalker->val, oldWalker->next, oldWalker->random);
            newWalker->next = newNode;
            newWalker = newWalker->next;
            ListMap[oldWalker] = newWalker;
            oldWalker = oldWalker->next;
        }
        
        newWalker = newHead;
        
        while(newWalker)
        {
            newWalker->random = ListMap[newWalker->random];
            newWalker = newWalker->next;
        }
        
        return newHead;
    }
};