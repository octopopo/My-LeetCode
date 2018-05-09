class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x/10 == 0)
            return true;
        string xS = to_string(x);
        int xSize = xS.size();
        for(int i = 0; i <xSize/2; i++){
            if(xS[i] != xS[xSize-1-i])
                return false;
        }
        
        return true;
    }
};