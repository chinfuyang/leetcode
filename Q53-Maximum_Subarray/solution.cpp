class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(2, INT_MIN));
        int max = nums[0];
        solve(dp, true, nums.size()-1, nums, max);

        return max;
    }

    int solve(std::vector<std::vector<int>>& dp, bool pick, int i, std::vector<int>& nums, int& max)
    {
        if (i <= 0) return nums[0];
        if (dp[i][pick] != INT_MIN)
            return dp[i][pick];

        dp[i][pick] = std::max(solve(dp, true, i - 1, nums, max), solve(dp, false, i-1, nums, max)) + nums[i];
        dp[i][!pick] = nums[i];

        int tmpMax = std::max(dp[i][pick], dp[i][!pick]);
        if (max < tmpMax)
        {
            max = tmpMax;
        }

        return tmpMax;
    }


};