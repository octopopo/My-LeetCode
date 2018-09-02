class Solution {
public:
    int numDecodings(string s) {
        int sL = s.size();
        if(sL == 0)
        {
            return 0;
        }
        
        int tempRes[sL];
        memset(tempRes,0,sL);
        
        
        if(s[0] != '0')
        {
            tempRes[0] = 1;
        }
        else
        {
            tempRes[0] = 0;
        }
        int tempS = 0;
        
        for(int i = 1; i < sL; i++)
        {
            tempRes[i] = 0;
            tempS = (s[i-1] - '0') * 10 + (s[i] - '0');
            if(tempS <= 26 && tempS >= 10)
            {
                if(i == 1)
                {
                    tempRes[i] += 1;
                }
                else
                {
                    tempRes[i] += tempRes[i-2];
                }
            }
            if(s[i] != '0')
            {
                tempRes[i] += tempRes[i-1];
            }
        }
        
        return tempRes[sL-1];
    }
};