class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sL = s.size();
        if(sL == 0 && find(wordDict.begin(), wordDict.end(), "") == wordDict.end())
        {
            return false;
        }
        else if(sL == 0)
        {
            return true;
        }
        
        //This 2-D array would store the result of string that start with position i and end with position j and see if it has
        //valid string
        bool isValid[sL][sL];
        memset(isValid, false, sizeof(isValid[0][0]) * sL * sL);
        
        int i, j, k;
        
        string temp;
        
        //i would be the length of the substring
        for(i = 1; i <= sL; i++)
        {
            //j would be the start position, -i part is mean to be not exceed the length of the string
            for(j = 0; j < sL-(i-1); j++)
            {
                //start from j with length i
                temp = s.substr(j, i);
                if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end())
                {
                    isValid[j][j+i-1] = true;
                }
                else
                {
                    for(k = j; k <= j+i-1; k++)
                    {
                        if(isValid[j][k] && isValid[k+1][j+i-1])
                        {
                            isValid[j][j+i-1] = true;
                            break;
                        }
                        isValid[j][j+i-1] = false;
                    }
                }
            }
        }
        
        
        return isValid[0][sL-1];
    }
};