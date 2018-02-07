class Solution {
public:
    int guessNumber(int n) {
        long low = 0;
        long high = n;
        long guessNum = (low + high) /2;
        int res = guess(guessNum);
        while(res != 0){
            if(res == 1){
                low = guessNum + 1;
            }
            else
                high = guessNum - 1;
            guessNum = (low + high) / 2;
            res = guess(guessNum);
        }
        
        return guessNum;
    }
};