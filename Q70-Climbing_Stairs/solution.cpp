class Solution
{
public:
    std::unordered_map<int, int> step = {{1, 1}, {2, 2}};
    int climbStairs(int n)
    {
        if (step.find(n) != step.end())
        {
            return step[n];
        }

        step[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return step[n];
    }
};