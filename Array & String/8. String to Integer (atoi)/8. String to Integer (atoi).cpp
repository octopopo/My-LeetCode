class Solution {
public:
    int myAtoi(string str) {
        int startCount = 0;
        int i = 0;
        bool isNeg = false;
        int res = 0;
        int preRes = 0;
        while(str[i] == ' ')
        {
            i++;
        }
        
        if(str[i] != '-' && !isDigit(str[i]) && str[i] != '+')
        {
            return 0;
        }
        
        if(str[i] == '-')
        {
            isNeg = true;
            i++;
        }
        else if(str[i] == '+')
        {
            isNeg = false;
            i++;
        }
        
        while(isDigit(str[i]))
        {
            preRes = res;
            res *= 10;
            res += (str[i] - '0');
            if(res/10 != preRes)
            {
                return isNeg ? INT_MIN : INT_MAX;
            }
            i++;
        }
        
        return isNeg ? -1 * res : res;
    }
    
    bool isDigit(char c)
    {
        return (c <= '9' && c >= '0');
    }
    
};