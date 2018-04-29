class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int *stepCost;
        int height = grid.size();
        int width = grid[0].size();
        
        stepCost = new int[width];
        
        for(int i = 0; i < width; i++)
            stepCost[i] = 0;
        
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(i==0 && j==0){
                    stepCost[j] = grid[i][j];
                }
                else if(i==0){
                    stepCost[j] = stepCost[j-1] + grid[i][j];
                }
                else if(j==0)
                    stepCost[j] = stepCost[j] + grid[i][j];
                else
                    stepCost[j] = min(stepCost[j],stepCost[j-1]) + grid[i][j];
            }
        }
        
        return stepCost[width-1];
        
    }
};