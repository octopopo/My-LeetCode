class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n == 0)
        {
            return res;
        }
        int ptr = 1;
        int vS;
        int pow2 = 1;
        while(ptr <=n)
        {
            vS = res.size();
            for(int i = vS-1; i>=0; i--)
            {
                res.push_back(res[i] + pow2);
            }
            ptr++;
            pow2 *= 2;
        }
        
        return res;
    }
};