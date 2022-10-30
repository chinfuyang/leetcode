class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            int num = i;
            int sum = 0;
            while(num != 0)
            {
                sum += (num & 1);
                num >> 1;
            }
            ans.push_back(sum);
        }

        return ans;
    }
};