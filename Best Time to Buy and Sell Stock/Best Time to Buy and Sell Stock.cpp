class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        int pL = prices.size();
        int tarMin, tarMax;
        int resMax = INT_MIN;
        int tempRes = 0;
        tarMin = prices[0];
        tarMax = prices[0];
        for(int i = 0; i < pL; i++)
        {
            if(prices[i] < tarMin)
            {
                tarMin = prices[i];
                tarMax = 0;
            }
            else if(prices[i] > tarMax)
            {
                tarMax = prices[i];
            }
            tempRes = tarMax - tarMin;
            resMax = max(resMax, tempRes);
        }
        
        return resMax < 0 ? 0 : resMax;
    }
};