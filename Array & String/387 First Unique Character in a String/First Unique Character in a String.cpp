class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> m_map(26,INT_MIN);
        int sL = s.size();
        int temp;
        int comp = INT_MAX;
        int res = INT_MAX;
        //if the character appear for the first time, we set the map to the first appearance location
        for(int i = 0; i < sL; i++)
        {
            temp = s[i] - 'a';
            if(m_map[temp] == INT_MIN)
            {
                m_map[temp] = i;
            }
            // if it already appeared, we set the map to minus means that this number is no longer unique
            else if(m_map[temp] >= 0)
            {
                if(m_map[temp] == 0)
                {
                    m_map[temp] = -1;
                }
                else
                {
                    m_map[temp] *= -1;
                }
            }
        }
        
        //Second iteration to find out if there is any unique, if there is, who appears first.
        for(int i = 0; i < 26; i++)
        {
            if(m_map[i] >= 0)
            {
                if(m_map[i] < comp)
                {
                    comp = m_map[i];
                }
            }
        }
        
        return comp == INT_MAX ? -1 : comp;
    }
};