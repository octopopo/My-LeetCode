class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
        {
            vector<vector<int>> res;
            return res;
        }
        else if(n == 1)
        {
            vector<vector<int>> res {{1}};
            return res;
        }
        
        
        vector<vector<int>> res(n,vector<int>(n));
        int lastI = n*n;
        int count = 1;
        int i = 0, j = 0;
        int direction = 0;
        while(count <= lastI)
        {
            res[i][j] = count;
            if(direction == 0)
            {
                if(j == n-1 || res[i][j+1] != 0)
                {
                    direction = 1;
                    i++;
                }
                else
                {
                    j++;
                }
            }
            else if(direction == 1)
            {
                if(i == n-1 || res[i+1][j] != 0)
                {
                    direction = 2;
                    j--;
                }
                else
                {
                    i++;
                }
            }
            else if(direction == 2)
            {
                if(j == 0 || res[i][j-1] != 0)
                {
                    direction = 3;
                    i--;
                }
                else
                {
                    j--;
                }
            }
            else if(direction == 3)
            {
                if(i == 0 || res[i-1][j] != 0)
                {
                    direction = 0;
                    j++;
                }
                else
                {
                    i--;
                }
            }
            count++;
        }
        return res;
    }
};