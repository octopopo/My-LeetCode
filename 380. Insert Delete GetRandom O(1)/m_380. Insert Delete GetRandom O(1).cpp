class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        eleCount = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(posRec.count(val) == 0)
        {
            numV.push_back(val);
            posRec[val] = eleCount;
            eleCount++;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(posRec.count(val))
        {
            int elePos = posRec[val];
            numV[elePos] = numV[eleCount-1];
            posRec[numV[elePos]] = elePos;
            numV.pop_back();
            posRec.erase(val);
            eleCount--;
            return true;
        }
        return false;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return numV[rand() % (eleCount)];
    }
    
private:
    vector<int> numV;
    unordered_map<int, int> posRec;
    int eleCount;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */