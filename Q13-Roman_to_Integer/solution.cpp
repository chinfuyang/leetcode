
class Solution {
public:
	int romanToInt(std::string s) {
		std::unordered_map<std::string, int> mapping;
		mapping["I"] = 1;
		mapping["V"] = 5;
		mapping["X"] = 10;
		mapping["L"] = 50;
		mapping["C"] = 100;
		mapping["D"] = 500;
		mapping["M"] = 1000;
		mapping["IV"] = 4;
		mapping["IX"] = 9;
		mapping["XL"] = 40;
		mapping["XC"] = 90;
		mapping["CD"] = 400;
		mapping["CM"] = 900;

		std::string nextChar = "";
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int numeral = 0;
			if ((i + 1) < (s.size()))
			{
				nextChar.append(1, s[i + 1]);
			}
			if (mapping.find(s[i] + nextChar) != mapping.end())
			{
				sum += mapping[s[i] + nextChar];
				i++;
			}
			else
			{
				std::string str;
				str.append(1, s[i]);
				sum += mapping[str];
			}
			nextChar = "";
		}

		return sum;
	}
};