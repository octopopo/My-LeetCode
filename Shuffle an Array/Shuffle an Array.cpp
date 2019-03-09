class Solution {
private:
    vector<vector<int>> permutationArrays;
    int permutationListCount;
    vector<int> baseArray;
public:
    Solution(vector<int> nums) {
        baseArray.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return baseArray;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(baseArray.size(), 0);
        getPermutation(-1, baseArray, res);
        return res;
    }
    
    void getPermutation(int position, vector<int> remainingBase, vector<int>& res)
    {
        if(position == baseArray.size()-1)
        {
            return;
        }
        position += 1;
        int remainLength = remainingBase.size();
        //cout << "position: " << position << " remainLength: " << remainLength << endl;
        int randNum = rand()%remainLength;
        res[position] = remainingBase[randNum];
        remainingBase.erase(remainingBase.begin() + randNum);
        getPermutation(position, remainingBase, res);
        return;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */