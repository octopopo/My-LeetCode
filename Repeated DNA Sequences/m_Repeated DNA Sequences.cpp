class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> stringMap;
        string temp_10;
        vector<string> result;
        int stringL = s.size();
        //the reason with <= is because that the position it start is a little bit different
        for(int i = 0; i <= stringL-10;i++){
            //substr(pos, length)
            temp_10 = s.substr(i,10);
            stringMap[temp_10]++;
            temp_10 = "";
        }
        
        for(auto i = stringMap.begin(); i != stringMap.end(); i++){
            if(i->second > 1){
                result.push_back(i->first);
            }
        }
        
        return result;
    }
};