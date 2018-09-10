class Solution {
public:
    int strStr(string haystack, string needle) {
        int hL = haystack.size();
        int nL = needle.size();
        if(nL == 0)
        {
            return 0;
        }
        if(hL == 0)
        {
            return -1;
        }
        if(nL > hL)
        {
            return -1;
        }
        
        string tempRes = "";
        
        for(int i = 0; i <= hL-nL; i++)
        {
            if(haystack[i] == needle[0])
            {
                for(int j = 0; j < nL; j++)
                {
                    tempRes += haystack[i+j];
                }
                if(tempRes == needle)
                {
                    return i;
                }
                else
                {
                    tempRes = "";
                }
            }
        }
        
        return -1;
    }
};