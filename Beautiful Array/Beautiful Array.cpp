class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res(N);
        int ptr = 0;
        if(N == 1)
        {
            res[ptr] = 1;
        }
        else
        {
            //The idea of the beautiful array is that to avoid the constrain
            //we put odd number on the left
            //evne number on the right
            //so that their sum would never be 2 * array[K] since it's always be odd
            //And we divide and conquer the problem, so that the sub-array on both side will obey the constrain
            vector<int> lArray = beautifulArray((N+1)/2);
            for(int i = 0; i < lArray.size(); i++)
            {
                res[ptr] = lArray[i] * 2 - 1;
                ptr++;
            }
            vector<int> rArray = beautifulArray(N/2);
            
            for(int j = 0; j < rArray.size(); j++)
            {
                res[ptr] = rArray[j] * 2;
                ptr++;
            }
        }
        
        return res;
    }
};