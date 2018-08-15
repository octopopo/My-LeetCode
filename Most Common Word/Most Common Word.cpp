class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int pL = paragraph.size();
        if(pL == 0)
        {
            return "";
        }
        unordered_map<string,int> m_map;
        bool isSet = false;
        string res;
        char temp;
        for(int i = 0; i < pL; i++)
        {
            temp = isCharacter(paragraph[i]);
            if(temp != '.')
            {
                if(!isSet)
                {
                    isSet = true;
                    res = "";
                    res += temp;
                }
                else
                {
                    res += temp;
                }
            }
            else
            {
                if(isSet)
                {
                    m_map[res]++;
                    isSet = false;
                }
            }
        }
        
        if(isSet)
        {
            m_map[res]++;
        }
        
        int targetCount = 0;
        int tempCount;
        string targetString;
        
        for(auto it = m_map.begin(); it != m_map.end(); it++)
        {
            res = it->first;
            tempCount = it->second;
            auto lookIt = find(banned.begin(), banned.end(), res);
            if(lookIt == banned.end())
            {
                if(tempCount > targetCount)
                {
                    targetCount = tempCount;
                    targetString = res;
                }
            }
        }
        
        return targetString;
    }
    
    char isCharacter(char c)
    {
        if((c >= 'a') && (c <= 'z'))
        {
            return c;
        }
        if((c >= 'A') && (c <= 'Z'))
        {
            return c-'A'+'a';
        }
        return '.';
    }
    
};