class Solution {
public:
    static bool oddEvenComp(int a, int b)
    {
        if(b%2 != 0)
        {
            return true;
        }
        return false;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        int aLength = A.size();
        vector<int> res (aLength);
        int oldCounter = 0;
        for(int i = 0; i < aLength; i++)
        {
            if(A[i]%2 == 0)
            {
                res[oldCounter] = A[i];
                oldCounter++;
            }
        }
        
        for(int i = 0; i < aLength; i++)
        {
            if(A[i]%2 != 0)
            {
                res[oldCounter] = A[i];
                oldCounter++;
            }
        }
        
        return res;
    }
};