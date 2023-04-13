class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> ans;
        int cur = 0;
        int n = intervals.size();

        while (cur < n && intervals[cur][1] < newInterval[0])
            ans.push_back(intervals[cur++]);
        
        while(cur < n && (newInterval[1] >= intervals[cur][0]))
        {
            newInterval[0] = std::min(newInterval[0], intervals[cur][0]);
            newInterval[1] = std::max(newInterval[1], intervals[cur][1]);
            cur++;
        }
        ans.push_back(newInterval);

        while(cur < n)
        {
            ans.push_back(intervals[cur++]);
        }

        return ans;
    }
};