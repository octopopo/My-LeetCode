class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rowL = board.size();
        int colL = board[0].size();
        int tempC = 0;
        //0 --> 4 if it is alive
        //1 --> 3 if it dies
        //1 --> 5 it it is still alive
        for(int i = 0; i < rowL; i++)
        {
            for(int j = 0; j < colL; j++)
            {
                tempC = 0;
                if(i != 0)
                {
                    tempC += (board[i-1][j] % 2);
                    if(j != 0)
                    {
                        tempC += (board[i-1][j-1] % 2);
                    }
                    if(j != colL-1)
                    {
                        tempC += (board[i-1][j+1] % 2);
                    }
                    if(i != rowL-1)
                    {
                        tempC+= (board[i+1][j] %2);
                        if(j != 0)
                        {
                            tempC += (board[i+1][j-1] % 2);
                        }
                        if(j != colL-1)
                        {
                            tempC += (board[i+1][j+1] % 2);
                        }
                    }
                }
                else
                {
                    if(i != rowL -1)
                    {
                        tempC+= (board[i+1][j] %2);
                        if(j != 0)
                        {
                            tempC += (board[i+1][j-1] % 2);
                        }
                        if(j != colL-1)
                        {
                            tempC += (board[i+1][j+1] % 2);
                        }
                    }
                }
                if(j != 0)
                {
                    tempC += (board[i][j-1] % 2);
                }
                if(j != colL-1)
                {
                    tempC += (board[i][j+1] % 2);
                }
                
                //cout << i << " " << j << " " << board[i][j] << " " << tempC << endl;
                
                if(board[i][j] == 0)
                {
                    if(tempC == 3)
                    {
                        board[i][j] = 4;
                    }
                }
                else
                {
                    if(tempC >= 2 && tempC <= 3)
                    {
                        board[i][j] = 5;
                    }
                }
            }
        }
        
        for(int i = 0; i < rowL; i++)
        {
            for(int j = 0; j < colL; j++)
            {
                board[i][j] /= 4;
            }
        }
        
        return;
    }
};