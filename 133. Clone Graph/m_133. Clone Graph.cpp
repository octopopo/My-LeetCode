/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> m_map;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
        {
            return NULL;
        }
        
        UndirectedGraphNode *head = new UndirectedGraphNode(0);
        head->neighbors.push_back(graphClone(node));
        
        return head->neighbors[0];
    }
    
    UndirectedGraphNode *graphClone(UndirectedGraphNode *node)
    {
        if(!node)
        {
            return NULL;
        }
        UndirectedGraphNode *newUGNode;
        
        int nLabel = node->label;
        int nCount = node->neighbors.size();
        if(!m_map.count(nLabel))
        {
            newUGNode = new UndirectedGraphNode(nLabel);
            m_map[nLabel] = newUGNode;
            for(int i = 0; i < nCount; i++)
            {
                newUGNode->neighbors.push_back(graphClone(node->neighbors[i]));
            }
        }
        else
        {
            return m_map[nLabel];
        }
        
        return newUGNode;
    }
};