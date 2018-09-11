class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowL = matrix.size();
        int colL = matrix[0].size();
        int col0 = 1;
        
        for(int i = 0; i < rowL; i++)
        {
            if(matrix[i][0] == 0)
            {
                col0 = 0;
            }
            for(int j = 1; j < colL; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //cout << matrix[0][0] << endl;
        
        for(int j = 1; j < colL; j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 0; i < rowL; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < rowL; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 0; j < colL; j++)
                {
                    matrix[i][j] = 0;                
                }
            }
        }
        
        if(col0 == 0)
        {
            for(int i = 0; i < rowL; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
        return;
        
    }
};