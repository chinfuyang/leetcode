#include <vector>

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int l, r, mid;
		if (nums.size() == 1 && nums[0] == target) return 0;
		else if (nums.size() == 1 && nums[0] != target) return -1;
		l = 0;
		r = nums.size() - 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] < target)
				l = mid + 1;
			else
				r = mid - 1;
		}

		return -1;
	}
};