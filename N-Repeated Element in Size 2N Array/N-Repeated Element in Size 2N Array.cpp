class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> mSet;
        
        for(int i : A)
        {
            if(mSet.count(i))
            {
                return i;
            }
            mSet.insert(i);
        }
        
        return 0;
    }
};