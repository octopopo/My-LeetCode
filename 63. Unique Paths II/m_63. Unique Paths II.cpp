class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(row == 0 || col == 0)
        {
            return 0;
        }
        
        vector<vector<int>> tempRec(row, vector<int>(col,0));
        
        tempRec[0][0] = 1;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    tempRec[i][j] = 0;
                    continue;
                }
                else
                {
                    if(i != 0)
                    {
                        tempRec[i][j] += tempRec[i-1][j];
                    }
                    if(j != 0)
                    {
                        tempRec[i][j] += tempRec[i][j-1];
                    }
                }
            }
        }
        
        return tempRec[row-1][col-1];
    }
};