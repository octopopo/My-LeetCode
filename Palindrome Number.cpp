class Solution {
public:
    bool isPalindrome(int x) {
        string numS = to_string(x);
        int n = numS.size();
        for(int i = 0; i < n/2; i++){
            if(numS[i] != numS[n-i-1]){
                return false;
            }
        }
        return true;
    }
};