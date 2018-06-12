class Solution {
public:
    int reverse(int x) {
        bool isMin;
        long tempX;
        int res = 0;
        int rem;
        bool isStart = false;
        if(x < 0){
            isMin = true;
            tempX = -1 * x;
        }
        else{
            isMin = false;
            tempX = x;
        }
        
        while(tempX > 0){
            if(res > INT_MAX/10){
                return 0;
            }
            if(res == INT_MAX/10){
                if(isMin && tempX > 8)
                    return 0;
                if(!isMin && tempX > 7)
                    return 0;
            }
            rem = tempX % 10;
            if(!isStart){
                if(rem == 0){
                    tempX /= 10;
                    continue;
                }
                else{
                    isStart = true;
                }
            }
            res *= 10;
            res += rem;
            tempX /= 10;
        }
        
        if(isMin){
            return -1 * res;
        }
        else{
            return res;
        }
    }
};