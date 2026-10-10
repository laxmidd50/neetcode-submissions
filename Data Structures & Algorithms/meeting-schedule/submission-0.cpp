/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        unordered_set<int> schedule;
        for (Interval interval: intervals)
        {
            for (int i = interval.start; i < interval.end; i++)
            {
                if (schedule.contains(i))
                    return false;
                schedule.insert(i);
            }
        }
        return true;
    }
};
