class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> m_map;
        int nL = nums.size();
        vector<vector<int>> resV;
        vector<int> tempRes;
        int tempSum ;
        map<int, int>::iterator got;
        if(nums.size() < 3)
        {
            return resV;
        }
        for(int i = 0; i < nL; i++)
        {
            m_map[nums[i]]++;
        }
        
        for(auto i = m_map.begin(); i != m_map.end(); ++i)
        {
            if(i->first > 0)
            {
                break;
            }
            for(int j = 1; j <= i->second; j++)
            {
                if(j == 1)
                {
                    for(auto k = next(i,1); k != m_map.end(); ++k)
                    {
                        k->second--;
                        tempSum =-1 * (i->first + k->first);
                        if(tempSum < 0)
                        {
                            k->second ++;
                            break;
                        }
                        got = m_map.find(tempSum);
                        if(got != m_map.end() && got->second != 0 && got->first != i->first && got->first >= k->first)
                        {
                            resV.push_back({i->first, k->first,got->first});
                            tempRes.clear();
                        }
                        k->second++;
                    }
                }
                else if(j == 2)
                {
                    tempSum = -2 * i->first;
                    got = m_map.find(tempSum);
                    i->second-=2;
                    if(got != m_map.end() && got->second > 0)
                    {
                        resV.push_back({i->first, i->first, got->first});
                        tempRes.clear();
                    }
                    i->second +=2;
                }
            }
            m_map.erase(i->first);
        }
        
        return resV;
    }
};