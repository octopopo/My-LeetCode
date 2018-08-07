class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        
        string::iterator i = s.begin(), j = i;
        
        while(i != s.end())
        {
            if(*i != ' ')
            {
                j = i+1;
                while(j != s.end() && *j != ' ')
                {
                    j++;
                }
                reverse(i,j);
                i = j;
                if(i == s.end() || ++i == s.end())
                {
                    break;
                }
            }
            else
            {
                i = s.erase(i);
            }
        }
        
        if(*(s.rbegin()) == ' ')
        {
            s.pop_back();
        }
        
        return;
    }
};