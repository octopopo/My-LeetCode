class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sSize = s.size();
        set<char> m_set;
        set<char>::iterator it;
        int count = 0;
        int maxR = 0;
        int temp = 0;
        
        for(int i = 0; i < sSize; i++){
            count = 0;
            for(int j = i; j < sSize; j++){
                it = m_set.find(s[j]);
                if(it != m_set.end())
                    break;
                else{
                    m_set.insert(s[j]);
                    count++;
                }
            }
            maxR = max(count, maxR);
            m_set.erase(m_set.begin(), m_set.end());
        }
        
        return maxR;
    }
};