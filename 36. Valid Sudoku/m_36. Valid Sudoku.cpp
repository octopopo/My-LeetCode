class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j;
        bool isRow[10], isCol[10];
        memset(isRow, false, 10);
        memset(isCol, false, 10);
        char rowI, colI;
        //examine if the row and col has followed the rule
        for(i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                rowI = board[i][j];
                if(rowI != '.')
                {
                    int rowIndex = rowI - '0';
                    if(isRow[rowIndex])
                    {
                        return false;
                    }
                    isRow[rowIndex] = true;
                }
                
                colI = board[j][i];
                if(colI == '.')
                {
                    continue;
                }
                else
                {
                    int colIndex = colI - '0';
                    if(isCol[colIndex])
                    {
                        return false;
                    }
                    isCol[colIndex] = true;
                }
            }
            memset(isRow, false, 10);
            memset(isCol, false, 10);
        }
        
        //check if the 3*3 area has followed the rule
        for(int a = 0; a < 9; a+=3)
        {
            for(int b = 0; b < 9; b+=3)
            {
                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 3; j++)
                    {
                        rowI = board[a+i][b+j];
                        if(rowI == '.')
                        {
                            continue;
                        }
                        else
                        {
                            int rowIndex = rowI - '0';
                            if(isRow[rowIndex])
                            {
                                return false;
                            }
                            isRow[rowIndex] = true;
                        }
                    }
                }
                memset(isRow, false, 10);
            }
        }
        return true;
    }
};