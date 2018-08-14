class Solution {
public:
    string reorganizeString(string S) {
        int sL = S.size();
        if(sL <= 1)
        {
            return S;
        }
        if(sL == 2)
        {
            if(S[0] == S[1])
            {
                return "";
            }
            else
            {
                return S;
            }
        }
        float sH = sL/2.0f;
        int maxC = 0;
        int mPos;
        vector<float> m_map(26, 0);
        string res(sL,'0');
        int tPos = 0;
        int i;
        for(i = 0; i < sL; i++)
        {
            m_map[getPos(S[i])]++;
        }
        
        for(i = 0; i < 26; i++)
        {
            if(maxC < m_map[i])
            {
                maxC = m_map[i];
                mPos = i;
            }
            if(m_map[i] - sH >= 1.0f)
            {
                return "";
            }
        }
        int index = 0;
        for(i = 0; i < m_map[mPos]; i++)
        {
            res[index] = getChar(mPos);
            index+=2;
        }
        m_map[mPos] = 0;
        for(i = 0; i < 26; i++)
        {
            while(m_map[i] > 0)
            {
                if(index >= sL)
                {
                    index = 1;
                }
                res[index] = getChar(i);
                index+=2;
                m_map[i]--;
            }
        }
        
        return res;
        
        
        
        
        return res;
    }
    
    int getPos(char a)
    {
        return a - 'a';
    }
    
    char getChar(int i)
    {
        return i + 'a';
    }
};