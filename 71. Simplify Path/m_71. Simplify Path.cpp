class Solution {
public:
    string simplifyPath(string path) {
        stack<string> res;
        string tempS = "";
        string resS = "";
        int pL = path.size();
        if(pL == 0)
        {
            return resS;
        }
        
        for(int i = 0; i < pL; i++)
        {
            if(tempS == "")
            {
                if(path[i] == '/')
                {
                    continue;
                }
                else if(path[i] == '.')
                {
                    tempS += path[i];
                }
                else
                {
                    tempS += path[i];
                }
            }
            else if(tempS == ".")
            {
                if(path[i] == '/')
                {
                    tempS = "";
                }
                else
                {
                    tempS += path[i];
                }
            }
            else if(tempS == "..")
            {
                if(path[i] == '/')
                {
                    if(!res.empty())
                    {
                        res.pop();
                    }
                    tempS = "";
                }
                else
                {
                    tempS += path[i];
                }
            }
            else
            {
                if(path[i] == '/')
                {
                    res.push(tempS);
                    tempS = "";
                }
                else
                {
                    tempS += path[i];
                }
            }
        }
        if(tempS != "" && tempS != "." && tempS != "..")
        {
            res.push(tempS);
            tempS = "";
        }
        else if(tempS == "..")
        {
            if(!res.empty())
            {
                res.pop();
            }
        }
        
        while(!res.empty())
        {
            tempS = res.top();
            resS = "/" + tempS + resS;
            res.pop();
        }
        
        if(resS == "")
        {
            resS = "/";
        }
        
        return resS;
    }
};