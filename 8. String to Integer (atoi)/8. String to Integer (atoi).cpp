class Solution {
public:
    int myAtoi(string str) {
        int sL = str.size();
        if(sL == 0)
        {
            return 0;
        }
        int res = 0;
        bool isNegative = false;
        char tempChar;
        int tempInt;
        int oldRes;
        bool isCounting = false;
        for(int i = 0; i < sL; i++)
        {
            tempChar = str[i];
            //res == 0 means it hasn't start counting
            if(!isCounting)
            {
                if(tempChar == ' ')
                {
                    continue;
                }
                else if(tempChar == '-')
                {
                    isNegative = true;
                    isCounting = true;
                }
                else if(tempChar == '+')
                {
                    isNegative = false;
                    isCounting = true;
                }
                else if(tempChar <= '9' && tempChar >= '0')
                {
                    res = tempChar - '0';
                    isCounting = true;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(tempChar <= '9' && tempChar >= '0')
                {
                    tempInt = tempChar - '0';
                    oldRes = res;
                    //that means times 10 will overflow
                    if(res*10/10 != oldRes)
                    {
                        return isNegative ? INT_MIN : INT_MAX;
                    }
                    
                    res = res*10;
                    int tempRes = INT_MAX - res;
                    if(tempRes <= 10)
                    {
                        if(isNegative)
                        {
                            if(tempInt > 8)
                            {
                                return INT_MIN;
                            }    
                        }
                        else
                        {
                            int tempRes = INT_MAX - res;
                            if(tempInt > 7)
                            {
                                return INT_MAX;
                            }
                        }
                    }
                    res += tempInt;
                }
                else
                {
                    return isNegative ? -res : res;
                }
            }
        }
        return isNegative ? -res : res;
    }
};