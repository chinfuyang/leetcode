class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return true;

        std::sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size() - 1; i++)
        {
            if ((intervals[i][1]) > intervals[i+1][0])
            {
                return false;
            }
        }

        return true;
    }
    /**
     * @brief Map Version
     * 
     * @param intervals 
     * @return true 
     * @return false 
     */
    bool canAttendMeetingsMapVersion(vector<vector<int>>& intervals) {
        std::map<int, int> durations;
        if (intervals.size() == 0)
            return true;

        for (int i = 0; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int duration = intervals[i][1] - intervals[i][0];
            auto it = durations.find(start);
            if (it != durations.end())
                return false;
            else
                durations.insert(std::pair<int, int>(start, duration));
        }

        for (auto it = durations.begin(); it != std::prev(durations.end()); ++it)
        {
            if ((it->first + it->second) > std::next(it)->first)
                return false;
        }

        return true;
    }
};