class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;
        char tempC;
        for(char c : s)
        {
            switch(c)
            {
                case '(':
                case '{':
                case '[':
                    pStack.push(c);
                    break;
                case ')':
                    if(pStack.empty())
                    {
                        return false;
                    }
                    tempC = pStack.top();
                    pStack.pop();
                    if(tempC != '(')
                    {
                        return false;
                    }
                    break;
                case ']':
                    if(pStack.empty())
                    {
                        return false;
                    }
                    tempC = pStack.top();
                    pStack.pop();
                    if(tempC != '[')
                    {
                        return false;
                    }
                    break;
                case '}':
                    if(pStack.empty())
                    {
                        return false;
                    }
                    tempC = pStack.top();
                    pStack.pop();
                    if(tempC != '{')
                    {
                        return false;
                    }
                    break;
            }
        }
        
        return pStack.empty();
    }
};