class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxD = 0;
        for(int i = 0; i < arrays.size()-1; i++){
            for(int j = i+1; j < arrays.size();j++){
                int iS = arrays[i].size()-1;
                int jS = arrays[j].size()-1;
                int temp1 = abs(arrays[i][0] - arrays[j][jS]);
                int temp2 = abs(arrays[j][0] - arrays[i][iS]);
                int temp = max(temp1,temp2);
                maxD = max(temp,maxD);
            }
        }
        return maxD;
    }
};