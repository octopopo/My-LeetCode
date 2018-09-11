class Solution {
public:
    bool isPalindrome(string s) {
        int sL = s.size();
        if(sL == 0)
        {
            return true;
        }
        int head = 0;
        int tail = sL-1;
        char headChar, tailChar;
        
        while(head <= tail)
        {
            while(!isAlphaNumeric(s[head]))
            {
                head++;
            }
            if(s[head] >= 'A' && s[head] <= 'Z')
            {
                headChar = s[head] - 'A' + 'a';
            }
            else
            {
                headChar = s[head];
            }
            
            while(!isAlphaNumeric(s[tail]))
            {
                tail--;
            }
            
            if(head > tail)
            {
                break;
            }
            
            if(s[tail] >= 'A' && s[tail] <= 'Z')
            {
                tailChar = s[tail] - 'A' + 'a';
            }
            else
            {
                tailChar = s[tail];
            }
            
            if(tailChar != headChar)
            {
                return false;
            }
            
            head++;
            tail--;
        }
        
        return true;
    }
    
    bool isAlphaNumeric(char tempChar)
    {
        if((tempChar >= 'a' && tempChar <= 'z') || (tempChar >= 'A' && tempChar <= 'Z') || (tempChar >= '0' && tempChar <= '9'))
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};