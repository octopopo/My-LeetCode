class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int cL = candidates.size();
        vector<vector<int>> res;
        set<vector<int>> resSet;
        //this map is for recording every combination of the candidates
        sort(candidates.begin(), candidates.end());
        map<int, set<vector<int>>> m_map;
        map<int, int> recMap;
        
        if(cL == 0)
        {
            return res;
        }
        
        int tempTarget;
        int tempC;
        int tempSum;
        
        for(int i = 0; i < cL; i++)
        {
            tempC = candidates[i];
            if(tempC > target)
            {
                break;
            }
            if(tempC == target)
            {
                vector<int> tempV{tempC};
                resSet.insert(tempV);
            }
            map<int, set<vector<int>>> tempMap(m_map.begin(), m_map.end());
            for(auto a = m_map.begin(); a != m_map.end(); a++)
            {
                tempSum = tempC + a->first;
                //cout <<"tempC: " << tempC << " a->first: " << a->first << " tempSum: " << tempSum << endl;
                if(tempSum > target)
                {
                    break;
                }
                set<vector<int>> tempSet = a->second;
                for(auto b = tempSet.begin(); b != tempSet.end(); b++)
                {
                    vector<int> setV = *b;
                    setV.push_back(tempC);
                    if(tempSum == target)
                    {
                        resSet.insert(setV);
                    }
                    else if(tempSum < target)
                    {
                        tempMap[tempSum].insert(setV);
                    }
                }
            }
            m_map = tempMap;
            vector<int> tempVV{tempC};
            m_map[tempC].insert(tempVV);
        }
        
        res.insert(res.end(), resSet.begin(), resSet.end());
        
        return res;
    }
};