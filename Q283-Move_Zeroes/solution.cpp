class Solution
{
public:
	void moveZeroes(vector<int> &nums)
	{
		int zeroCnt = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				zeroCnt++;
			else if (nums[i] != 0)
			{
				nums[i - zeroCnt] = nums[i];
				nums[i] = 0;
			}
		}
		return nums;
	}
};