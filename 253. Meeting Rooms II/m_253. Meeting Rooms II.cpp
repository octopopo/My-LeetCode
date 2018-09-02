/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool myCompare(Interval interA, Interval interB)
    {
        return interA.end < interB.end;
    }
    
    static bool myC(int a, int b)
    {
        return a > b;
    }
    
    int minMeetingRooms(vector<Interval>& intervals) {
        int iL = intervals.size();
        if(iL == 0)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), myCompare);
        
        int roomCount = 0;
        vector<int> roomRecord;
        
        int i = 0;
        while(intervals[i].end == 0)
        {
            i++;
        }
        roomCount++;
        roomRecord.push_back(intervals[i].end);
        i++;
        int j;
        for(i; i < iL; i++)
        {
            for(j = 0; j < roomCount; j++)
            {
                if(intervals[i].start >= roomRecord[j])
                {
                    roomRecord[j] = intervals[i].end;
                    break;
                }
            }
            if(j == roomCount)
            {
                roomRecord.push_back(intervals[i].end);
                roomCount++;
            }
            sort(roomRecord.begin(), roomRecord.end(), myC);
        }
        
        return roomCount;
    }

};