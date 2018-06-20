class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pS = prices.size();
        if(pS == 0 || pS == 1)
        {
            return 0;
        }
        int res = 0;
        int j;
        for(int i = 0; i < pS-1; i++)
        {
            j = i+1;
            res += max((prices[j] - prices[i]), 0);
        }
        
        return res;
    }
};