class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 10 && x >= 0)
        {
            return true;
        }
        if(x < 0 || x%10 == 0)
        {
            return false;
        }
        
        int comp = 0;
        int temp;
        
        while(comp < x)
        {
            
            temp = x%10;
            x /= 10;
            comp *= 10;
            comp += temp;
        }
        
        if(comp == x || (x != 0 && comp != 0 && comp/10 == x))
        {
            return true;
        }
        
        return false;
    }
};