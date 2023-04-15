class Solution
{
public:
    /**
     * @brief Runtime: 60ms Beat 11.93%, Memory: 22.2MB Beat 6.56%
     *
     * @param intervals
     * @return vector<vector<int>>
     */
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> ans;
        std::queue<std::vector<int>> q;

        if (intervals.size() == 1)
            return intervals;

        for (int i = 0; i < intervals.size() - 1; ++i)
        {
            std::vector<int> newInterval = intervals[i];
            std::vector<int> nextInterval = intervals[i + 1];
            if (!q.empty())
            {
                newInterval = q.front();
                q.pop();
            }

            if (newInterval[1] >= nextInterval[0])
            {
                intervals[i + 1][0] = std::min(newInterval[0], nextInterval[0]);
                intervals[i + 1][1] = std::max(newInterval[1], nextInterval[1]);
                q.emplace(intervals[i + 1]);
            }
            else
            {
                ans.emplace_back(newInterval);
            }
        }

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            ans.emplace_back(front);
        }

        if (intervals[intervals.size() - 1][0] > ans[ans.size() - 1][1])
        {
            ans.emplace_back(intervals[intervals.size() - 1]);
        }

        return ans;
    }
};