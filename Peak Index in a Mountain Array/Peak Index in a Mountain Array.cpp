class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if(A[0] > A[1])
        {
            return 0;
        }
        for(int i = 1; i < A.size()-1; i++)
        {
            //cout << A[i] << endl;
            if(A[i] > A[i-1])
            {
                if(A[i] > A[i+1])
                {
                    return i;
                }
            }
        }
        return A.size() - 1;
    }
};