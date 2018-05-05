class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = INT_MIN;
        int st = 0;
        int ed = height.size()-1;
        int ht;
        while(st < ed){
            ht = min(height[st], height[ed]);
            maxA = max(maxA,(ed-st) * ht);
            
            //this step is really interesting, since we start with maximum width, and we test with it decreasingly.
            //so if the height are not exceed the height we just test, the volume will definitely not exceed our maxA
            //so we only test the volume, once the height on both end are higher
            while(height[st] <= ht && st < ed)
                st++;
            while(height[ed] <= ht && st < ed)
                ed--;
        }
        
        return maxA;
    }
};