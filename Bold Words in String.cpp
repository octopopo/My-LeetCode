class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = words.size();
        vector<bool> mask(S.size());
        bool foundIt;
        for(int i = 0; i < n; i++){
            string temp = S;
            for(int j = 0; j < S.size(); j++){
                if(S[j] == words[i][0]){
                    foundIt = true;
                    for(int a = 0; a < words[i].size();a++){
                        if(words[i][a] != S[j+a]){
                            foundIt = false;
                        }
                    }
                    if(foundIt){
                        for(int a = 0; a <words[i].size();a++){
                            mask[j+a] = true;
                        }
                    }
                }
            }
        }
        bool isUp = false;
        int cnt = 1;
        string realRes;
        for(int i = 0; i < S.size(); i++){
            if(i == 0){
                if(mask[i]){
                    isUp = true;
                    realRes.append("<b>");
                }
                realRes.append(1, S[i]);
            }
            else{
                if(!isUp){
                    if(mask[i]){
                        isUp = true;
                        realRes.append("<b>");
                        cnt+=3;
                    }
                    realRes.append(1,S[i]);
                }
                else{
                    if(!mask[i]){
                        isUp = false;
                        realRes.append("</b>");
                    }
                    realRes.append(1,S[i]);
                }
                if(isUp && i == S.size() -1){
                    realRes.append("</b>");
                }
            }
        }
        return realRes;
    }
};