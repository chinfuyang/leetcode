class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int numCnt = 0;
        long long maxSum = 0, curSum = 0;
        std::unordered_map<int, int> _m;
        
        for (int i = 0; i < nums.size(); i++)
        {
            _m[nums[i]]++;
            numCnt++;
            curSum += nums[i];

            if (numCnt == k)
            {
                if (_m.size() == k)
                {
                    maxSum = std::max(maxSum, curSum);
                }
                _m[nums[i+1-k]]--;
                curSum -= nums[i+1-k];
                if (_m[nums[i+1-k]]==0)
                {
                    _m.erase(nums[i+1-k]);
                }
                numCnt--;
            }
        }
        
        return maxSum;
    }
};