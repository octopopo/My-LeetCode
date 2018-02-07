class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < words[i].size(); j++){
                if(words[j].size() <= i){
                    return false;
                }
                if(j >= words.size())
                    return false;
                if(words[j][i] != words[i][j])
                    return false;
            }
        }
        
        return true;
    }
};