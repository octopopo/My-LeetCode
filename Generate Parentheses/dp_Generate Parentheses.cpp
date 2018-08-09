class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
        {
            res.push_back("");
            return res;
        }
        
        for(int i = 0; i < n; i++)
        {
            for(string left : generateParenthesis(i))
            {
                for(string right : generateParenthesis(n-i-1))
                {
                    res.push_back("(" + left + ")" + right);
                }
            }
        }
        
        return res;
    }
};