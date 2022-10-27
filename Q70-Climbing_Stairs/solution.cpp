class Solution
{
public:

    int climbStairs(int n)
    {
        std::unordered_map<int, int> map;
        map = {{1,1}, {2,2}};

        for (int i = 3; i <= n; i++)
        {
            map[i] = map[i-1] + map[i-2];
        }

        return map[n];
    }
};