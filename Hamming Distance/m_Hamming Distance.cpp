class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int temp = x ^ y;
        for(int i = 0; i < 32, temp != 0; i++){
            if(temp & 1 == 1)
                res++;
            temp = temp >> 1;
        }
        return res;
    }