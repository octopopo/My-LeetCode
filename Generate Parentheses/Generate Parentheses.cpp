class Solution {
public:
    int totalP;
    vector<string> generateParenthesis(int n) {
        totalP = n;
        int count = 0;
        return getParenthesis(n, count);
    }
    
    vector<string> getParenthesis(int n, int count)
    {
        vector<string> res;
        vector<string> temp1, temp2;
        string tempString;
        //n is counting how many parenthesises left,
        //count is for counting how many left parenthesis haven't been complimented
        if(n == 0 && count == 0)
        {
            return res;
        }
        else if(n == 0 && count != 0)
        {
            temp1 = getParenthesis(n, count-1);
            if(temp1.size() == 0)
            {
                res.push_back(")");
            }
            for(string str : temp1)
            {
                tempString = ")" + str;
                res.push_back(tempString);
            }
        }
        else if(n == 5 && count == 0)
        {
            temp1 = getParenthesis(n-1, count+1);
            for(string str: temp1)
            {
                tempString = "(" + str;
                res.push_back(tempString);
            }
        }
        else
        {
            if(count == 0)
            {
                temp1 = getParenthesis(n-1, count+1);
                for(string str : temp1)
                {
                    tempString = "(" + str;
                    res.push_back(tempString);
                }
            }
            else
            {
                temp1 = getParenthesis(n-1, count+1);
                for(string str : temp1)
                {
                    tempString = "(" + str;
                    res.push_back(tempString);
                }
                
                temp2 = getParenthesis(n, count-1);
                for(string str : temp2)
                {
                    tempString = ")" + str;
                    res.push_back(tempString);
                }
            }
        }
        return res;     
    }
};