class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sL = strs.size();
        vector<vector<string>> res;
        if(sL == 0)
        {
            return res;
        }
        unordered_map<string, vector<string>> m_map;
        string temp;
        for(int i = 0; i < sL; i++)
        {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            m_map[temp].push_back(strs[i]);
        }
        
        
        for(auto j = m_map.begin(); j != m_map.end(); j++)
        {
            res.push_back(j->second);
        }
        
        return res;
    }
};