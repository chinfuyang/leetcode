class Solution {
public:
	long long makeIntegerBeautiful(long long n, int target) {
		if (digitSum(n, target) <= target) return 0;

		long long tmpN = n;
		long long  x = 0;
		int tenCnt = 0;
		int digit = 0;
		while (1)
		{
			long long powTen = std::pow(10, tenCnt);
			digit = (tmpN / powTen) % 10;
			while (digit == 0)
			{
				tenCnt++;
				powTen = std::pow(10, tenCnt);
				digit = (tmpN / powTen) % 10;
			}
			x = x +  std::pow(10, tenCnt);
			tmpN += std::pow(10, tenCnt);
			if (digitSum(tmpN, target) <= target)
			{
				return x;
			}
		}
	}

private:
	long long digitSum(long long n, int target)
	{
		long long sum = 0;
		while (n != 0)
		{
			sum += n % 10;
			n = n / 10;
			if (sum > target)
				break;
		}

		return sum;
	}
};