class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do
        {
            slow = getHappy(slow);
            fast = getHappy(getHappy(fast));
        } while(slow != fast);
        return slow == 1;
    }
    
    
    int getHappy(int n)
    {
        int res = 0, temp;
        while(n != 0)
        {
            temp = n%10;
            res += (temp * temp);
            n/=10;
        }
        return res;
    }
};