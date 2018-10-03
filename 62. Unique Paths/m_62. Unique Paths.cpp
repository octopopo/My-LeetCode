class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tempRec(n,vector<int>(m));
        if(m == 0 || n == 0)
        {
            return 0;
        }
        
        for(int i = 0; i < n; i++)
        {
            tempRec[i][0] = 1;
        }
        
        for(int j = 0; j < m; j++)
        {
            tempRec[0][j] = 1;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                tempRec[i][j] = tempRec[i-1][j] + tempRec[i][j-1];
            }
        }
        
        return tempRec[n-1][m-1];
    }
};