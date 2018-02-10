class Solution {
public:
    int numWays(int n, int k) {
        vector<int> fenceWithSame;
        vector<int> fenceWithDiff;
        if(n == 0)
            return 0;
        if(n == 1)
            return k;
        fenceWithSame.push_back(k);
        fenceWithSame.push_back(k);
        fenceWithDiff.push_back(k);
        fenceWithDiff.push_back(k*(k-1));
        for(int i = 2; i < n; i++){
            fenceWithDiff.push_back(fenceWithDiff[i-1] * (k-1) + fenceWithSame[i-1] * (k-1));
            fenceWithSame.push_back(fenceWithDiff[i-1]);
        }
        cout << fenceWithDiff[n-1] << " " << fenceWithSame[n-1] << endl;
        return fenceWithDiff[n-1] + fenceWithSame[n-1];
    }
};