class Solution {
public:
    string longestPalindrome(string s) {
        int sSize = s.size();
        int i, j;
        int maxSize = 0;
        int maxI, maxJ;
        string res;
        vector<vector<int>> m_temp = vector<vector<int>>(sSize, vector<int>(sSize));
        
        for(i = 0; i < sSize; i++)
        {
            m_temp[i][0] = 1;
            if(m_temp[i][0] > maxSize)
            {
                maxSize = m_temp[i][0];
                maxI = i;
                maxJ = 0;
            }
            if(i+1 < sSize)
            {
                if(s[i] == s[i+1])
                {
                    m_temp[i][1] = 2;
                    if(m_temp[i][1] > maxSize)
                    {
                        maxSize = m_temp[i][1];
                        maxI = i;
                        maxJ = 1;
                    }
                }
                else
                {
                    m_temp[i][1] = 0;
                }
            }
        }
        
        for(j = 2; j < sSize; j++)
        {
            for(i = 0; i < sSize; i++)
            {
                if(i + j > sSize)
                    break;
                if(s[i] == s[i+j])
                {
                    if(m_temp[i+1][j-2] == 0)
                        continue;
                    m_temp[i][j] = m_temp[i+1][j-2] + 2;
                    if(m_temp[i][j] > maxSize)
                    {
                        maxSize = m_temp[i][j];
                        maxI = i;
                        maxJ = j;
                    }
                }
                else
                {
                    m_temp[i][j] = 0;
                }
            }
        }
        
        for(i = maxI; i <= maxI+maxJ; i++)
        {
            res.push_back(s[i]);
        }
        
        return res;
    }
};