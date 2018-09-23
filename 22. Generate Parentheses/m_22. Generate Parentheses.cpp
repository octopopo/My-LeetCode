class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
        {
            return res;
        }
        
        res = getParenthesis(n);
        
        return res;
    }
    
    vector<string> getParenthesis(int n)
    {
        vector<string> res;
        if(n == 0)
        {
            res.push_back("");
            return res;
        }
        vector<string> temp1, temp2;
        for(int i = 0; i < n; i++)
        {
            temp1 = getParenthesis(i);
            temp2 = getParenthesis(n-1-i);
            for(int j = 0; j < temp1.size(); j++)
            {
                for(int k = 0; k < temp2.size(); k++)
                {
                    res.push_back("(" + temp1[j] + ")" + temp2[k]);
                }
            }
        }
        
        return res;
    }
    
};