class Solution {
public:
    int lengthOfLastWord(string s) {
        int sL = s.size();
        if(sL == 0)
        {
            return 0;
        }
        
        int isStartCount = 0;
        int count = 0;
        
        for(int i = sL-1; i >= 0; i--)
        {
            if(isStartCount == 0)
            {
                if(s[i] == ' ')
                {
                    continue;
                }
                else
                {
                    count = 1;
                    isStartCount = 1;
                }
            }
            else if(isStartCount == 1)
            {
                if(s[i] != ' ')
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        
        return count;
        
    }
};