class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int mL = M.size();
        int circleCount = 0;
        for(int i = 0; i < mL; i++)
        {
            if(M[i][i] == 1)
            {
                circleCount++;
                M[i][i] = 0;
                deleteCircle(M, i, mL);
            }
        }
        
        return circleCount;
    }
    
    void deleteCircle(vector<vector<int>>& M, int i, int mL)
    {
        //cout << i << j << endl;
        for(int k = 0; k < mL; k++)
        {
            if(M[i][k] == 1)
            {
                M[i][k] = 0;
                M[k][i] = 0;
                M[k][k] = 0;
                deleteCircle(M, k, mL);
            }
        }
        
        return;
    }
};