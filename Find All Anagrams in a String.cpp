class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sum = 0;
        int count = 1;
        vector<int> lookTable(26);
        int pSize = p.size();
        
        vector<int> res;
        
        if(s.size() == 0 || p.size() == 0)
            return res;
        
        for(char a : p){
            int tar = a - 'a';
            if(lookTable[tar] == 0){
                lookTable[tar] = count;
                count++;
            }
            sum += lookTable[tar];
        }
        int tempSum = 0;
        
        for(int j = 0; j < s.size(); j++){
            int sTar = s[j] - 'a';
            if(j > pSize-1){
                int tar = s[j-pSize] - 'a';
                tempSum = tempSum - lookTable[tar];
            }
            tempSum = tempSum + lookTable[sTar];
            if(j >= pSize-1 && tempSum == sum){
                
                res.push_back(j - pSize+1);
            }
        }
        
        return res;
        
    }
};