class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int aS = A.size();
        int bS = B.size();
        
        int bigB = ceil((float)bS/(float)aS);
        string bigA;
        int i = 0;
        for(i = 0; i <= bigB+1; i++, bigA+=A){
            if(bigA.find(B) != string::npos){
                return i;
            }
        }
        
        return -1;
    }
};