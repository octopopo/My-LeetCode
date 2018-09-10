/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a, Interval b)
{
    return a.start < b.start;
}
class Solution {
public:
    
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> m_vector;
        int iL = intervals.size();
        if(iL == 0)
        {
            return m_vector;
        }
        
        int tempS, tempE;
        //sort these intervals by starting time
        sort(intervals.begin(), intervals.end(), compare);
        tempS = intervals[0].start;
        tempE = intervals[0].end;
        
        int iE,iS;
        
        for(int i = 1; i < iL; i++)
        {
            iS = intervals[i].start;
            if(iS <= tempE)
            {
                iE = intervals[i].end;
                if(iE > tempE)
                {
                    tempE = iE;
                }
            }
            else
            {
                Interval newI(tempS, tempE);
                m_vector.push_back(newI);
                tempS = iS;
                tempE = intervals[i].end;
            }
        }
        
        Interval newI(tempS, tempE);
        m_vector.push_back(newI);
        
        return m_vector;
    }
};