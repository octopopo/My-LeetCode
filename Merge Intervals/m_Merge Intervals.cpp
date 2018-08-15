/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static bool myfunction(Interval a, Interval b)
{
    //cout << a.start << ":" << b.start << endl;
    return a.start < b.start;
}
class Solution {
public:
    
    vector<Interval> merge(vector<Interval>& intervals) {
        int iL = intervals.size();
        if(iL == 0)
        {
            return intervals;
        }
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), myfunction);
        
        bool isLooking = false;
        
        int targetStart, targetEnd;
        
        
        
        targetStart = intervals[0].start;
        targetEnd = intervals[0].end;
        
        
        
        for(int i = 0; i < iL; i++)
        {
            Interval temp = intervals[i];
            if(temp.start > targetEnd)
            {
                Interval newT(targetStart, targetEnd);
                res.push_back(newT);
                targetStart = temp.start;
                targetEnd = temp.end;
            }
            else
            {
                targetEnd = max(targetEnd, temp.end);
            }
            if(i == iL-1)
            {
                Interval newT(targetStart, targetEnd);
                res.push_back(newT);
            }
        }
        
        return res;
    }
};