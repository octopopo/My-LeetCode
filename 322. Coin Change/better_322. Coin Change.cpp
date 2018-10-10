class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int totalA = amount+1;
        int cL = coins.size();
        
        vector<int> tempRes(amount+1, totalA);
        tempRes[0] = 0;
        for(int i = 0; i <= amount; i++)
        {
            for(int j = 0; j < cL; j++)
            {
                if(coins[j] <= i)
                {
                    tempRes[i] = min(tempRes[i], tempRes[i-coins[j]] + 1);
                }
            }
        }
        
        return tempRes[amount] == totalA ? -1 : tempRes[amount];
    }
};