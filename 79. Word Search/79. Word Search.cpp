class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char, vector<pair<int, int>>> charToPos;
        
        int rowCount = board.size();
        int colCount = board[0].size();
        
        pair<int, int> tempP;
        char tempC;
        
        int tempX, tempY;
        vector<pair<int, int>> tempV;
        
        //construct both map
        for(int i = 0; i < rowCount; i++)
        {
            for(int j = 0; j < colCount; j++)
            {
                tempC = board[i][j];
                tempP = make_pair(i, j);
                charToPos[tempC].push_back(tempP);      
            }
        }
        
        auto it = charToPos.find(word[0]);
        
        if(it == charToPos.end())
        {
            return false;
        }
        else
        {
            tempV = it->second;
            for(int i = 0; i < tempV.size(); i++)
            {
                tempX = tempV[i].first;
                tempY = tempV[i].second;
                tempC = board[tempX][tempY];
                board[tempX][tempY] = ' ';
                bool res = findChar(tempX, tempY, board, word, 1, rowCount, colCount);
                board[tempX][tempY] = tempC;
                if(res)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool findChar(int i, int j, vector<vector<char>>& board, string word, int whichC, int rowCount, int colCount)
    {
        //cout << i << " " << j << " " << word[whichC] << endl;
        if(word.size() <= whichC)
        {
            return true;
        }
        char targetC = word[whichC];
        char tempC;
        int tempX = i;
        int tempY = j;
        bool res;
        tempX--;
        if(tempX >= 0)
        {
            tempC = board[tempX][tempY];
            if(tempC == targetC )
            {
                board[tempX][tempY] = ' ';
                res = findChar(tempX, tempY, board, word, whichC+1, rowCount, colCount);
                if(res)
                {
                    return true;
                }
                board[tempX][tempY] = tempC;
            }
        }
        tempX+=2;
        if(tempX< rowCount)
        {
            tempC = board[tempX][tempY];
            if(tempC == targetC )
            {
                board[tempX][tempY] = ' ';
                res = findChar(tempX, tempY, board, word, whichC+1, rowCount, colCount);
                if(res)
                {
                    return true;
                }
                board[tempX][tempY] = tempC;
            }
        }
        tempX--;
        tempY--;
        if(tempY>= 0)
        {
            tempC = board[tempX][tempY];
            if(tempC == targetC )
            {
                board[tempX][tempY] = ' ';
                res = findChar(tempX, tempY, board, word, whichC+1, rowCount, colCount);
                if(res)
                {
                    return true;
                }
                board[tempX][tempY] = tempC;
            }
        }
        tempY+=2;
        if(tempY <= colCount)
        {
            tempC = board[tempX][tempY];
            if(tempC == targetC )
            {
                board[tempX][tempY] = ' ';
                res = findChar(tempX, tempY, board, word, whichC+1, rowCount, colCount);
                if(res)
                {
                    return true;
                }
                board[tempX][tempY] = tempC;
            }
        }
        
        return false;
        
    }
};