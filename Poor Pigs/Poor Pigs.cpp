class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int testTimes = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(testTimes));
        
    }
};