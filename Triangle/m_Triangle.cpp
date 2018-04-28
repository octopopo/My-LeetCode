class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int triangle_height = triangle.size();
        int triangle_width = triangle[triangle_height-1].size();
        int *stepCost;
        int tempSize;
        
        //stepCost denotes steps that end with nth step of ith triangle
        stepCost = new int[triangle_width];
        //do remember to clean up the array to 0
        for(int i = 0; i < triangle_width; i++){
            stepCost[i] = 0;
        }
        
        //using DP to solve the problem, the recursion function should be stepCost[j] = triangle[i][j] + min(stepCost[j], stepCost[j-1])
        for(int i = 0; i < triangle_height; i++){
            tempSize = triangle[i].size();
            if(i == 0)
                stepCost[0] = stepCost[0] + triangle[i][0];
            else{
                for(int j = tempSize-1; j >= 0; j--){
                    if(j == 0){
                        stepCost[j] = stepCost[j] + triangle[i][j];
                    }
                    else if(j == tempSize-1){
                        stepCost[j] = stepCost[j-1] + triangle[i][j];
                    }
                    else{
                        stepCost[j] = triangle[i][j] + min(stepCost[j], stepCost[j-1]);
                    }
                }
            }
        }
        
        int minStep = INT_MAX;
        for(int i = 0; i < triangle_width; i++){
            minStep = minStep < stepCost[i] ? minStep : stepCost[i];
        }
        
        return minStep;
    }
    
};