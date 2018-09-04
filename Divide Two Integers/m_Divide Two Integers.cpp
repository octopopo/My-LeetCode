class Solution {
public:
    int divide(int dividend, int divisor) {
        map<int, int> m_map;
        int tempStateProcess = 1;
        int originalDi = divisor;
        int originalDD = dividend;
        
        if(divisor < 0)
        {
            if(dividend > 0)
            {
                if(-1 * dividend > divisor)
                {
                    return 0;
                }
            }
        }
        
        if(divisor == 1)
        {
            return dividend;
        }
        bool isMin = (dividend < 0) ^ (divisor < 0) ? true : false;
        if(dividend < 0)
        {
            if(dividend == INT_MIN)
            {
                dividend = INT_MAX;
            }
            else
            {
                dividend = -dividend;
            }
        }
        
        if(divisor < 0)
        {
            if(divisor == INT_MIN)
            {
                divisor = INT_MAX;
            }
            else
            {
                divisor = -divisor;
            }
        }
        
        if(dividend < divisor)
        {
            return 0;
        }
        
        int lastDiv = 0;
        int res = 0;
        int tempRes = 0;
        
        if(divisor == 1)
        {
            return isMin ? -dividend : dividend;
        }
        
        while(dividend >= divisor)
        {
            m_map[divisor] = tempStateProcess;
            lastDiv = divisor;
            tempStateProcess *= divisor;
            divisor *= divisor;
            if(lastDiv != divisor/lastDiv)
            {
                break;
            }
        }
        
        for(auto i = m_map.rbegin(); i!= m_map.rend(); i++)
        {
            while(dividend >= i->first)
            {
                dividend -= i->first;
                tempRes = res;
                res += i->second;
                if(tempRes != res - i->second)
                {
                    return INT_MAX;
                }
                
            }
        }
        
        if(originalDi == 2 && originalDD == INT_MIN)
        {
            res ++;
        }
        
        return res = isMin ? -res : res;
    }
};