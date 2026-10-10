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
    int minMeetingRooms(vector<Interval>& intervals) {
        unordered_map<int, int> schedule;
        int rooms = 0;
        for (Interval interval: intervals)
        {
            for (int i = interval.start; i < interval.end; i++)
            {
                schedule[i]++;
                if (schedule[i] > rooms)
                    rooms = schedule[i];
            }
        }
        return rooms;
    }
};
