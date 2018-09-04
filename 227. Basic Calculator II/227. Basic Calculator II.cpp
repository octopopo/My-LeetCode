class Solution {
public:
    int calculate(string s) {
        stack<int> m_stack;
        int tempSum = 0;
        int tempTop;
        int res = 0;
        // + -> 0
        // - -> 1
        // * -> 2
        // / -> 3
        int operatorBefore = 0;
        for(char c : s)
        {
            if(c <= '9' && c >= '0')
            {
                tempSum = tempSum * 10 + (c - '0');
            }
            else if(c == ' ')
            {
                continue;
            }
            else
            {
                if(operatorBefore == 1)
                {
                    tempSum = -tempSum;
                }
                else if(operatorBefore == 2)
                {
                    tempTop = m_stack.top();
                    tempSum *= tempTop;
                    m_stack.pop();
                }
                else if(operatorBefore == 3)
                {
                    tempTop = m_stack.top();
                    tempSum = tempTop/tempSum;
                    m_stack.pop();
                }
                //cout << tempSum << endl;
                m_stack.push(tempSum);
                tempSum = 0;
                if(c == '+')
                {
                    operatorBefore = 0;
                }
                else if(c == '-')
                {
                    operatorBefore = 1;
                }
                else if(c == '*')
                {
                    operatorBefore = 2;
                }
                else if(c == '/')
                {
                    operatorBefore = 3;
                }
            }
        }
        if(operatorBefore == 1)
        {
            tempSum = -tempSum;
        }
        else if(operatorBefore == 2)
        {
            tempTop = m_stack.top();
            tempSum *= tempTop;
            m_stack.pop();
        }
        else if(operatorBefore == 3)
        {
            tempTop = m_stack.top();
            tempSum = tempTop/tempSum;
            m_stack.pop();
        }
        m_stack.push(tempSum);

        while(!m_stack.empty())
        {
            res += m_stack.top();
            m_stack.pop();
        }

        return res;
    }
};