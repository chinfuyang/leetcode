class Solution
{
public:
    /**
     * @brief Runtime: 1042ms Beat 7.19%, Memory: 186.8MB Beat 5.43%
     *
     */
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        std::vector<std::vector<int>> ans;

        std::partial_sort(points.begin(), points.begin() + k, points.end(), [](std::vector<int> a, std::vector<int> b)
                          { return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]); });

        for (int i = 0; i < k; ++i)
        {
            ans.emplace_back(points[i]);
        }

        return ans;
    }
    /**
     * @brief Runtime: 307ms Beat 41.14%, Memory: 89MB Beat 13.6%
     *
     * @param points
     * @param k
     * @return vector<vector<int>>
     */
    vector<vector<int>> kClosest2(vector<vector<int>> &points, int k)
    {
        std::map<long long int, std::vector<int>> m;
        std::vector<std::vector<int>> ans;

        for (int i = 0; i < points.size(); ++i)
        {
            long long int dis = std::pow(points[i][0], 2) + std::pow(points[i][1], 2);

            auto it = m.find(dis);
            if (it != m.end())
            {
                it->second.emplace_back(i);
            }
            else
            {
                std::vector<int> newPoints{i};
                m.insert(std::pair<long long int, std::vector<int>>(dis, newPoints));
            }
        }

        int cnt = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            auto indies = it->second;
            for (int i = 0; i < indies.size(); ++i)
            {
                ans.emplace_back(points[indies[i]]);
                if (++cnt >= k)
                    break;
            }
            if (cnt >= k)
                break;
        }

        return ans;
    }
};