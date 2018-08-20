class Solution {
public:
    int countPrimes(int n) {
        //using original array is much faster than using vector
        bool isPrime[n+1];
        memset(isPrime, true, sizeof(isPrime));
        
        //delete the number that is not prime
        for(int i = 2; i * i < n; i++)
        {
            if(isPrime[i])
            {
                for(int j = i * 2; j < n; j += i)
                {
                    if(isPrime[j])
                    {
                        isPrime[j] = false;
                    }
                }
            }
        }
        //count the prime number
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(isPrime[i])
            {
                count++;
            }
        }
        
        return count;
    }
};