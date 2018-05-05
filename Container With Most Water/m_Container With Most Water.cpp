class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = INT_MIN;
        int tempH = 0;
        int comH = 0;
        int hSize = height.size();
        int width;
        int tempC = 0;
        for(int i = 0; i < hSize; i++)
            tempH = max(tempH,height[i]);
        
        for(int i = hSize-1; i > 0; i--){
            if(maxA > i * tempH){
                break;
            }
            for(int j = 0; j+i < hSize; j++){
                maxA = max(maxA,i * min(height[j], height[j+i]));
            }
        }
        
        return maxA;
    }
};