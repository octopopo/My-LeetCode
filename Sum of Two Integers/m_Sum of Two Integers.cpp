class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        int temp;
        //using AND to get the carry of result
        carry = a & b;
        //using XOR to get the result of adding 
        res = a ^ b;
        while(carry != 0){
            carry = carry << 1;
            temp = res ^ carry;
            carry = res & carry;
            res = temp;
        }
        
        return res;
    }
};