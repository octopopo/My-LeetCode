class Solution {
public:
    bool isPalindrome(int x) {
        int compNum = 0;
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        if(x%10 == 0 && x != 0)
            return false;
        int rem = 0;
        
        while(compNum < x){
            rem = x%10;
            compNum = compNum * 10 + rem;
            x /= 10;
        }
        
        int cDT = compNum / 10;
        
        if(compNum == x)
            return true;
        else if(cDT == x && cDT != 0)
            return true;
        else
            return false;
        
    }
};