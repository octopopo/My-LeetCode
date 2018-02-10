class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x %10 == 0))
            return false;
        int sum = 0;
        //so we reverted only have the number and compare
        while(x > sum){
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        //notice that the sum/10 part is just incase that x has odd numbers
        return (x==sum) || (x == sum/10);
    }
};