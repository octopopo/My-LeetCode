class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int rowHalf = ceil((float)row/2);
        bool isOdd = row%2 == 0 ? false : true;
        row = row-1;
        int tempS;
        
        for(int i = 0; i < rowHalf; i++)
        {
            if(isOdd && i == rowHalf - 1)
            {
                continue;
            }
            for(int j = 0; j < rowHalf; j++)
            {
                tempS = matrix[i][j];
                matrix[i][j] = matrix[row-j][i];
                matrix[row-j][i] = matrix[row-i][row-j];
                matrix[row-i][row-j] = matrix[j][row-i];
                matrix[j][row-i] = tempS;
            }
        }
        return;
    }
};