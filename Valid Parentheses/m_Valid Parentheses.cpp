class Solution {
public:
    bool isValid(string s) {
        int sSize = s.size();
        char* m_stack = (char*)malloc(sizeof(char) * (sSize + 1));
        int top = 0;
        char temp;
        if(sSize % 2 == 1)
            return false;
        for(int i = 0; i < sSize; i++){
            temp = s[i];
            if(temp == '{' || temp == '(' || temp == '['){
                m_stack[top++] = temp;
            }
            else{
                if(temp == '}'){
                    if(m_stack[--top] != '{')
                        return false;
                }
                else if(temp == ']'){
                    if(m_stack[--top] != '[')
                        return false;
                }
                else if(temp == ')'){
                    if(m_stack[--top] != '(')
                        return false;
                }
            }
        }
        return top == 0 ? true : false;
    }
};