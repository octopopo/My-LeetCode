class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m_map({{'M', 1000}, {'D', 500}, {'C', 100,}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}});
        int sL = s.size();
        int res = 0;
        char tempC;
        for(int i = 0; i < sL; i++)
        {
            tempC = s[i];
            if(tempC == 'C')
            {
                if(i+1 < sL && (s[i+1] == 'M'||s[i+1] == 'D'))
                {
                    res -= m_map[tempC];
                    
                }
                else
                {
                    res += m_map[tempC];
                }
            }
            else if(tempC == 'X')
            {
                if(i+1 < sL && (s[i+1] == 'L'||s[i+1] == 'C'))
                {
                    res -= m_map[tempC];
                }
                else
                {
                    res += m_map[tempC];
                }
            }
            else if(tempC == 'I')
            {
                if(i+1 < sL && (s[i+1] == 'V'||s[i+1] == 'X'))
                {
                    res -= m_map[tempC];
                }
                else
                {
                    res += m_map[tempC];
                }
            }
            else
            {
                res += m_map[tempC];
            }
            
        }
        
        return res;
    }
};