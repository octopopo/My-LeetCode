class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        map<int ,set<int>> m_map;
        vector<int> res;
        for(int n : nums)
        {
            countMap[n]++;
        }
        
        for(auto i : countMap)
        {
            m_map[i.second].insert(i.first);
        }
        
        for(auto i = m_map.rbegin(); i != m_map.rend(); i++)
        {
            for(int s : i->second)
            {
                res.push_back(s);
                k--;
                if(k == 0)
                {
                    break;
                }
            }
            
            if(k == 0)
            {
                break;
            }
        }
        
        return res;
    }
};