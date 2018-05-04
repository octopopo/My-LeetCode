class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        
        string res = "";
        int strNum = strs.size();
        char tar;
        int minL = INT_MAX;
        bool isSame = true;
        int tSize;
        for(int i = 0; i < strNum; i++){
            tSize = strs[i].size();
            minL = min(minL,tSize);
        }
        
        for(int i = 0; i < minL; i++){
            tar = strs[0][i];
            for(int j = 1; j < strNum; j++){
                if(strs[j][i] != tar){
                    isSame = false;
                    break;
                }
            }
            if(!isSame)
                break;
            else{
                res += tar;
            }
        }
        
        return res;
    }
};