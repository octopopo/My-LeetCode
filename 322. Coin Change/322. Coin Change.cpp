class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
        {
            return 0;
        }
        
        int cL = coins.size();
        if(cL == 0)
        {
            return -1;
        }
        sort(coins.begin(), coins.end());
        
        vector<vector<int>> tempRec(cL+1, vector<int>(amount+1, INT_MAX));
        
       // memset(*tempRec, INT_MAX, sizeof(tempRec));
        
        int coinCount = 0;
        int tempRes;
        int tempLoop;
        int tempAmount;
        int tempCoins;
        
        for(int i = 1; i <= cL; i++)
        {
            tempCoins = coins[i-1];
            for(int j = 1; j <= amount; j++)
            {
                tempRec[i][j] = tempRec[i-1][j];
                tempLoop = j / tempCoins;
                for(int k = 0; k <= tempLoop; k++)
                {
                    tempAmount = j - tempCoins * k;
                    if(tempAmount == 0)
                    {
                        tempRec[i][j] = k;
                    }
                    else if(tempAmount > 0)
                    {
                        if(tempRec[i][tempAmount] == INT_MAX)
                        {
                            continue;
                        }
                        else
                        {
                            tempRes = tempRec[i][tempAmount] + k;
                            tempRec[i][j] = min(tempRec[i][j], tempRes);
                        }
                    }
                }
            }
        }
        
        return tempRec[cL][amount] == INT_MAX ? -1 : tempRec[cL][amount];
        
    }
};