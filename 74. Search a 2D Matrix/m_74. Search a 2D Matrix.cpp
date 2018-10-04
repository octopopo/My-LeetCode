class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0)
        {
            return 0;
        }
        int col = matrix[0].size();
        if(col == 0)
        {
            return 0;
        }
        if(target < matrix[0][0])
        {
            return false;
        }
        int tarRow;
        int i;
        //find which row it should be in
        for(i = 0; i < row; i++)
        {
            if(matrix[i][0] == target)
            {
                return true;
            }
            if(matrix[i][0] > target)
            {
                break;
            }
        }
        
        tarRow = i-1;
        
        //after you got the row, use binary search to search this row
        int begin = 0, end = col-1;
        int mid = (begin + end) / 2;
        while(begin <= end)
        {
            if(matrix[tarRow][mid] == target)
            {
                return true;
            }
            else if(matrix[tarRow][mid] > target)
            {
                end = mid-1;
            }
            else if(matrix[tarRow][mid] < target)
            {
                begin = mid + 1;
            }
            mid = (begin + end) / 2;
        }
        
        return false;
    }
};