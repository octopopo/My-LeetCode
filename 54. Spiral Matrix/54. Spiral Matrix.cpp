class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if(row == 0)
        {
            return res;
        }
        int col = matrix[0].size();
        
        if(col == 0)
        {
            return res;
        }
        
        int i = 0;
        int j = 0;
            
        int direction = 0;
        
        bool isBeen[row][col];
        memset(isBeen, false, sizeof(isBeen[0][0]) * col * row);
        
        while(isBeen[i][j] != true)
        {
            //cout << i << " " << j << endl;
            res.push_back(matrix[i][j]);
            isBeen[i][j] = true;
            
            if(direction == 0)
            {
                if(j+1 == col || isBeen[i][j+1])
                {
                    direction = 1;
                    if(i+1 >= row)
                    {
                        break;
                    }
                    i++;
                    continue;
                }
                j++;
            }
            else if(direction == 1)
            {
                if(i+1 == row || isBeen[i+1][j])
                {
                    direction = 2;
                    if(j-1 < 0)
                    {
                        break;
                    }
                    j--;
                    continue;
                }
                i++;
            }
            else if(direction == 2)
            {
                if(j-1 == -1 || isBeen[i][j-1])
                {
                    direction = 3;
                    i--;
                    continue;
                }
                j--;
            }
            else if(direction == 3)
            {
                if(isBeen[i-1][j])
                {
                    direction = 0;
                    j++;
                    continue;
                }
                i--;
            }
        }
        
        return res;
    }
};