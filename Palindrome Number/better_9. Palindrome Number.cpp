class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0)
        {
            return true;
        }
        if(x < 0 || x%10 == 0)
        {
            return false;
        }
        
        int original = x;
        int reverseNumber = 0;
        
        int temp;
        
        while(x > 0)
        {
            temp = x%10;
            x /= 10;
            
            reverseNumber = reverseNumber * 10 + temp;
        }
        
        return reverseNumber == original ? true : false;
    }
};