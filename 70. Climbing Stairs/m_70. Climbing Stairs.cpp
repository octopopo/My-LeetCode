class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
        {
            return 0;
        }
        vector<int> tempRec(n+1);
        tempRec[0] = 1;
        tempRec[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            tempRec[i] = tempRec[i-1] + tempRec[i-2];
        }
        
        return tempRec[n];
    }
};