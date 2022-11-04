class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		std::stack<int> _s;
		std::vector<int> ans;
		_s.push(nums[0] * nums[0]);

		for (int i = 1; i < nums.size(); i++)
		{
			int square = nums[i] * nums[i];
			int top = _s.top();
			if (square > top)
			{
				ans.push_back(top);
				_s.pop();
				while (!_s.empty() && square > _s.top() )
				{
					top = _s.top();
					ans.push_back(top);
					_s.pop();
				}
				_s.push(square);
			}
			else
			{
				_s.push(square);
			}
		}

		while (!_s.empty())
		{
			int top = _s.top();
			ans.push_back(top);
			_s.pop();
		}

		return ans;
	}
};