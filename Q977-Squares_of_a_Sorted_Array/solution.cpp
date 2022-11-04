class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> ret(nums.size());
        int l = 0, r = nums.size() - 1;
        
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (std::abs(nums[l]) > std::abs(nums[r])) ret[i] = nums[l] * nums[l++];
            else ret[i] = nums[r] * nums[r--];
        }
        
		return ret;
	}
};