class Solution {
public:
    int rowCount;
    int colCount;
    int numIslands(vector<vector<char>>& grid) {
        int totalCount = 0;
        rowCount = grid.size();
        if(rowCount == 0)
        {
            return 0;
        }
        colCount = grid[0].size();
        
        for(int i = 0; i < rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                if(grid[i][j] == '1')
                {
                    totalCount++;
                    exploreIsland(grid, i, j);
                }
            }
        }
        
        return totalCount;
    }
    
    void exploreIsland(vector<vector<char>> &grid, int i, int j)
    {
        if(i >= rowCount || j >= colCount || j < 0 || i < 0)
        {
            return;
        }
        if(grid[i][j] == '1')
        {
            grid[i][j] = '2';
            exploreIsland(grid, i-1, j);
            exploreIsland(grid, i+1, j);
            exploreIsland(grid, i, j-1);
            exploreIsland(grid, i, j+1);
        }
        
        return;
    }
};